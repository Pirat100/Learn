#include "elev.h"

building::building() {
	char ustring[BUF_LENGTH]; // строка для номеров этажей

	init_graphics(); // инициализация графики
	clear_screen(); // очистка экрана
	num_cars = 0;
	for (int k = 0; k < NUM_CARS; ++k) {
		car_list[k] = new elevator(this, num_cars);
		num_cars++;
	}
	for (int j = 0; j < NUM_CARS; ++j) { // создать лифты
		set_cursor_pos(3, NUM_FLOORS - j); // вывести номер этажа
		itoa(j + 1, ustring, 10);
		cout << setw(3) << ustring;
		floor_request[UP][j] = false;
		floor_request[DN][j] = false;
	}
}

building::~building() {
	for (int k = 0; k < NUM_CARS; ++k) {
		delete car_list[k];
	}
}

void building::master_tick() {
	int j;
	show_floor_reqs();
	for (j = 0; j < NUM_CARS; ++j) {
		car_list[j]->car_tick1();
	}
	for (j = 0; j < NUM_CARS; ++j) {
		car_list[j]->car_tick2();
	}
}

void building::show_floor_reqs() const {
	for (int j = 0; j < NUM_FLOORS; ++j) {
		set_cursor_pos(SPACING, NUM_FLOORS - j);
		if (floor_request[UP][j] == true) {
			cout << '\x1E';
		} else {
			cout << ' ';
		}
		set_cursor_pos(SPACING + 3, NUM_FLOORS - j);

		if (floor_request[DN][j] == true) {
			cout << '\x1F';
		} else {
			cout << ' ';
		}
	}
}

void building::record_floor_reqs() {
	char ch = 'x';
	char ustring[BUF_LENGTH];
	int iFloor;
	char chDirection;

	set_cursor_pos(1, 22);
	cout << "Нажмите [Enter] для вызова лифта: ";
	if (!kbhit()) {
		return;
	}
	cin.ignore(10, '\n');
	if (ch == '\x1B') {
		exit(0);
	}
	set_cursor_pos(1,22);
	clear_line();

	set_cursor_pos(1,22);
	cout << "На каком Вы этаже? ";
	cin.get(ustring, BUF_LENGTH);
	cin.ignore(10, '\n');

	iFloor = atoi(ustring);

	cout << "В каком направлении будете двигаться (u/d): ";
	cin.get(chDirection);

	cin.ignore(10, '\n');

	if (chDirection == 'u' || chDirection == 'U') {
		floor_request[UP][iFloor - 1] = true;
	}
	if (chDirection == 'd' || chDirection == 'D') {
		floor_request[DN][iFloor - 1] = true;
	}
	set_cursor_pos(1,22);
	clear_line();
	set_cursor_pos(1,23);
	clear_line();
	set_cursor_pos(1,24);
	clear_line();
}

bool building::get_floor_req(const int dir, const int floor) const {
	return floor_request[dir][floor];
}

void building::set_floor_req(const int dir, const int floor, const bool updown)
{
	floor_request[dir][floor] = updown;
}

// получить номер этажа, на котором находится кабина лифта с указанным номером
int building::get_cars_floor(const int carNo) const
{
	return car_list[carNo]->get_floor();
}

// получить направление движения кабины лифта с указанным номером
direction building::get_cars_dir(const int carNo) const
{
	return car_list[carNo]->get_direction();
}


elevator::elevator(building* ptrB, int nc) : ptrBuilding(ptrB), car_number(nc) {
	current_floor = 0;
	old_floor = 0;
	current_dir = STOP;
	for (int j = 0; j < NUM_FLOORS; ++j) {
		destination[j] = false;
	}
	loading_timer = 0;
	unloading_timer = 0;
}

int elevator::get_floor() const {
	return current_floor;
}

void elevator::car_tick1() {
	car_display();
	dests_display();
	if (loading_timer) {
		--loading_timer;
	}
	if (unloading_timer) {
		--unloading_timer;
	}
	decide();
}

void elevator::car_tick2() {
	move();
}

void elevator::car_display() {
	set_cursor_pos(SPACING + (car_number + 1) * SPACING, NUM_FLOORS - old_floor);
	cout << "  ";
	set_cursor_pos(SPACING - 1 + (car_number + 1) * SPACING, NUM_FLOORS - current_floor);

	switch (loading_timer) {
	case 3:
		cout << "\x01\xDB \xDB ";
		break;
	case 2:
		cout << " \xDB\x01\xDB ";
		get_destinations();
		break;
	case 1:
		cout << " \xDB\xDB\xDB ";
		break;
	case 0:
		cout << " \xDB\xDB\xDB ";
		break;
	}

	set_cursor_pos(SPACING + (car_number + 2) * SPACING, NUM_FLOORS - current_floor);

	switch(unloading_timer) {
	case 3:
		cout << "\xDB\x01\xDB ";
		break;
	case 2:
		cout << "\xDB \xDB\x01";
		break;
	case 1:
		cout << "\xDB\xDB\xDB ";
		break;
	case 0:
		cout << "\xDB\xDB\xDB ";
		break;
	}
	old_floor = current_floor;
}

void elevator::dests_display() const {
	for (int j = 0; j < NUM_FLOORS; j++) {
		set_cursor_pos(SPACING - 2 + (car_number + 1) * SPACING, NUM_FLOORS - j);
		if (destination[j] == true) {
			cout << '\xFE';
		} else {
			cout << ' ';
		}
	}
}

void elevator::decide()
{
	int j;


	bool destins_above, destins_below;
	bool requests_above, requests_below;

	int nearest_higher_req = 0;
	int nearest_lower_req = 0;

	bool car_between_up, car_between_dn;

	bool car_opposite_up, car_opposite_dn;


	int ofloor;
	direction odir;


	if ((current_floor == NUM_FLOORS - 1 && current_dir == UP)
		|| (current_floor == 0 && current_dir == DN)) {
		current_dir = STOP;
	}

	if (destination[current_floor] == true) {
		destination[current_floor] = false;
		if (!unloading_timer) {
			unloading_timer = LOAD_TIME;
		}
		return;
	}

	if ((ptrBuilding->get_floor_req(UP, current_floor) && current_dir != DN)) {
		current_dir = UP;

		ptrBuilding->set_floor_req(current_dir, current_floor, false);
		if (!loading_timer) {
			loading_timer = LOAD_TIME;
		}
		return;
	}

	if ((ptrBuilding->get_floor_req(DN, current_floor) && current_dir != UP)) {
		current_dir = DN;

		ptrBuilding->set_floor_req(current_dir, current_floor, false);
		if (!loading_timer) {
			loading_timer = LOAD_TIME;
		}
		return;
	}

	destins_above = destins_below = false;
	requests_above = requests_below = false;
	for (j = current_floor + 1; j < NUM_FLOORS; j++) {
		if (destination[j]) {
			destins_above = true;
		}
		if (ptrBuilding->get_floor_req(UP, j) ||
			ptrBuilding->get_floor_req(DN, j)) {
			requests_above = true;
			if (!nearest_higher_req) {
				nearest_higher_req = j;
			}
		}
	}
	for (j = current_floor - 1; j >= 0; j--) {
		if (destination[j]) {
			destins_below = true;
		}
		if (ptrBuilding->get_floor_req(UP, j) ||
			ptrBuilding->get_floor_req(DN, j)) {
			requests_below = true;
			if (!nearest_lower_req) {
				nearest_lower_req = j;
			}
		}
	}


	if (!destins_above && !requests_above &&
		!destins_below && !requests_below) {
		current_dir = STOP;
		return;
	}


	if (destins_above && (current_dir == STOP || current_dir == UP)) {
		current_dir = UP;
		return;
	}
	if (destins_below && (current_dir == STOP || current_dir == DN)) {
		current_dir = DN;
		return;
	}

	car_between_up = car_between_dn = false;
	car_opposite_up = car_opposite_dn = false;
	for (j = 0; j < NUM_CARS; j++) {
		if (j != car_number) {
			ofloor = ptrBuilding->get_cars_floor(j);
			odir = ptrBuilding->get_cars_dir(j);


			if ((odir == UP || odir == STOP) && requests_above) {

				if ((ofloor > current_floor && ofloor <= nearest_higher_req)

					|| (ofloor == current_floor && j < car_number)) {
					car_between_up = true;
				}
			}

			if ((odir == DN || odir == STOP) && requests_below) {

				if ((ofloor < current_floor && ofloor >= nearest_lower_req)

					|| (ofloor == current_floor && j < car_number)) {
					car_between_dn = true;
				}
			}

			if ((odir == UP || odir == STOP) && requests_below) {

				if (nearest_lower_req >= ofloor
					&& nearest_lower_req - ofloor < current_floor - nearest_lower_req) {
					car_opposite_up = true;
				}
			}

			if ((odir == DN || odir == STOP) && requests_above) {

				if (ofloor >= nearest_higher_req
					&& ofloor - nearest_higher_req < nearest_higher_req - current_floor) {
					car_opposite_dn = true;
				}
			}
		}
	}

	if ((current_dir == UP || current_dir == STOP)
		&& requests_above && !car_between_up && !car_opposite_dn) {
		current_dir = UP;
		return;
	}

	if ((current_dir == DN || current_dir == STOP)
		&& requests_below && !car_between_dn && !car_opposite_up) {
		current_dir = DN;
		return;
	}

	current_dir = STOP;
}

void elevator::move()
{
	if (loading_timer || unloading_timer) {
		return;
	}
	if (current_dir == UP) {
		current_floor++;
	} else if (current_dir == DN)
		current_floor--;
}

void elevator::get_destinations()
{
	char ustring[BUF_LENGTH];
	int dest_floor;
	set_cursor_pos(1, 22);
	clear_line();
	set_cursor_pos(1, 22);
	cout << "Лифт " << (car_number + 1)
		<< " остановился на этаже " << (current_floor + 1)
		<< "\nЭтаж назначения (0 для окончания ввода).";

	for (int j = 1; j < NUM_FLOORS; j++) {

		set_cursor_pos(1, 24);
		cout << "Выбор " << j << " этажа назначения: ";

		cin.get(ustring, BUF_LENGTH);
		cin.ignore(10, '\n');
		dest_floor = atoi(ustring);
		set_cursor_pos(1, 24);
		clear_line();
		if (dest_floor == 0) {
			set_cursor_pos(1, 22);
			clear_line();
			set_cursor_pos(1, 23);
			clear_line();
			set_cursor_pos(1, 24);
			clear_line();
			return;
		}
		--dest_floor;

		if (dest_floor == current_floor) {
			--j;
			continue;
		}

		if (j == 1 && current_dir == STOP) {
			current_dir = (dest_floor < current_floor) ? DN : UP;
		}
		destination[dest_floor] = true;
		dests_display();
	}
}
