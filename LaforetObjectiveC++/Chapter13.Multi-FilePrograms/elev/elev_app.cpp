#include "elev.h"

int main() {
	building theBuilding;

	while (true) {
		theBuilding.master_tick(); // Послать временные метки вмем лифтам

		wait(1000); // пауза

		theBuilding.record_floor_reqs(); // получить запросы этажей от пользователя
	}
	return 0;
}
