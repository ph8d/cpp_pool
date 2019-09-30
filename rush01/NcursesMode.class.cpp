/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesMode.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 17:44:08 by hdanylev          #+#    #+#             */
/*   Updated: 2018/07/01 21:23:06 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcursesMode.class.hpp"

NcursesMode::NcursesMode() {
	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, true);
	start_color();
	timeout(1);
	init_pair (1, COLOR_CYAN, COLOR_BLACK);
	init_pair (2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair (3, COLOR_WHITE, COLOR_WHITE);
	init_pair (4, COLOR_YELLOW, COLOR_YELLOW);
	init_pair (5, COLOR_RED, COLOR_RED);
	init_pair (6, COLOR_GREEN, COLOR_GREEN);
	init_pair (7, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair (8, COLOR_GREEN, COLOR_BLACK);

	this->_row = 0;
	this->_col = 0;
	this->_story = 0;
}

NcursesMode::NcursesMode(NcursesMode const &ref) {
	*this = ref;
}


NcursesMode::~NcursesMode() {}

NcursesMode &NcursesMode::operator=(NcursesMode const &ref) {

	this->_row = ref._row;
	this->_col = ref._col;
	this->_story = ref._story;

	return (*this);
}

int NcursesMode::getCol() const {

	return (this->_col);
}

int NcursesMode::getRow() const {

	return (this->_row);
}

void NcursesMode::_drawing_blocks(int story) {

	float hight = HIGTH;
	float width = WIDTH;

	for (float j = _col / width; j < _col / 1.2; j++) {

		attron(COLOR_PAIR (3));
		mvprintw(_row / hight, j, "-");
		attroff(COLOR_PAIR (3));
	}

	for (float j = _col / width; j < _col / 1.2; j++) {

		_cats(_row / (hight / 2.43), _col / (width / 3.9), story);
		attron(COLOR_PAIR (3));
		mvprintw(_row / 1.77, j, "-");
		attroff(COLOR_PAIR (3));
	}

	for (float j = _col / width; j < _col / 1.65; j++) {

		attron(COLOR_PAIR (3));
		mvprintw(_row / 1.15, j, "-");
		attroff(COLOR_PAIR (3));
	}

	for (float i = _row / hight; i < _row / 1.15; i++) {
		
		attron(COLOR_PAIR (3));
		mvprintw(i, _col / width, "|");
		attroff(COLOR_PAIR (3));
	}
	for (float i = _row / hight; i < _row / 1.75; i++) {

		attron(COLOR_PAIR (3));
		mvprintw(i, _col / 1.2, "|");
		attroff(COLOR_PAIR (3));
	}
	for (float i = _row / hight; i < _row / 1.15; i++) {

		attron(COLOR_PAIR (3));
		mvprintw(i, _col / 2.65, "|");
		attroff(COLOR_PAIR (3));
	}
	for (float i = _row / hight; i < _row / 1.15; i++) {

		attron(COLOR_PAIR (3));
		mvprintw(i, _col / 1.65, "|");
		attroff(COLOR_PAIR (3));
	}
}

void NcursesMode::_cats(float row, float col, int story)
{
	if (story < 1) {
	
		mvaddstr(row++, col, "                                                          ");
		mvaddstr(row++, col, "            *      ,MMM8&&&.            *                 ");
		mvaddstr(row++, col, "                  MMMM88&&&&&    .                        ");
		mvaddstr(row++, col, "                 MMMM88&&&&&&&                            ");
		mvaddstr(row++, col, "     *           MMM88&&&&&&&&                            ");
		mvaddstr(row++, col, "                 MMM88&&&&&&&&                            ");
		mvaddstr(row++, col, "                 'MMM88&&&&&&'                            ");
		mvaddstr(row++, col, "                   'MMM8&&&'      *                       ");
		mvaddstr(row++, col, "          |\\___/|                                        ");
		mvaddstr(row++, col, "          )     (             .              '            ");
		mvaddstr(row++, col, "         =\\     /=                                       ");
		mvaddstr(row++, col, "          )===(       *                                   ");
		mvaddstr(row++, col, "          /     \\                                        ");
		mvaddstr(row++, col, "          |     |                                         ");
		mvaddstr(row++, col, "         /       \\                                       ");
		mvaddstr(row++, col, "         \\       /                                       ");
		mvaddstr(row++, col, "  _/\\_/\\_/\\__  _/_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_ ");
		mvaddstr(row++, col, "  |  |  |  |( (  |  |  |  |  |  |  |  |  |  |             ");
		mvaddstr(row++, col, "  |  |  |  | ) ) |  |  |  |  |  |  |  |  |  |             ");
		mvaddstr(row++, col, "  |  |  |  |(_(  |  |  |  |  |  |  |  |  |  |             ");
		mvaddstr(row++, col, "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |             ");
		mvaddstr(row++, col, "  jgs|  |  |  |  |  |  |  |  |  |  |  |  |  |             ");
	}
	else if (story < 3) {

		mvaddstr(row++, col, "                                                        ");
		mvaddstr(row++, col, "            *      ,MMM8&&&.            *               ");
		mvaddstr(row++, col, "                  MMMM88&&&&&    .                      ");
		mvaddstr(row++, col, "                 MMMM88&&&&&&&                          ");
		mvaddstr(row++, col, "     *           MMM88&&&&&&&&                          ");
		mvaddstr(row++, col, "                 MMM88&&&&&&&&                          ");
		mvaddstr(row++, col, "                 'MMM88&&&&&&'                          ");
		mvaddstr(row++, col, "                   'MMM8&&&'      *                     ");
		mvaddstr(row++, col, "          |\\___/|                                      ");
		mvaddstr(row++, col, "         =) ^Y^ (=            .              '          ");
		mvaddstr(row++, col, "          \\  ^  /                                      ");
		mvaddstr(row++, col, "           )=*=(      *                                 ");
		mvaddstr(row++, col, "          /     \\                                      ");
		mvaddstr(row++, col, "          |     |                                       ");
		mvaddstr(row++, col, "         /| | | |\\                                     ");
		mvaddstr(row++, col, "         \\| | |_|/\\                                   ");
		mvaddstr(row++, col, "  jgs_/\\_//_// ___/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_ ");
		mvaddstr(row++, col, "  |  |  |  | \\_) |  |  |  |  |  |  |  |  |  |          ");
		mvaddstr(row++, col, "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |           ");
		mvaddstr(row++, col, "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |           ");
		mvaddstr(row++, col, "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |           ");
		mvaddstr(row++, col, "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |           ");
	}
	else if (story < 5) {

		mvaddstr(row++, col, "                                                      ");
		mvaddstr(row++, col, "            *      ,MMM8&&&.            *             ");
		mvaddstr(row++, col, "                  MMMM88&&&&&    .                    ");
		mvaddstr(row++, col, "                 MMMM88&&&&&&&                        ");
		mvaddstr(row++, col, "     *           MMM88&&&&&&&&                        ");
		mvaddstr(row++, col, "                 MMM88&&&&&&&&                        ");
		mvaddstr(row++, col, "                 'MMM88&&&&&&'                        ");
		mvaddstr(row++, col, "                   'MMM8&&&'      *    _              ");
		mvaddstr(row++, col, "          |\\___/|                      \\            ");
		mvaddstr(row++, col, "         =) ^Y^ (=   |\\_/|              ||   '       ");
		mvaddstr(row++, col, "          \\  ^  /    )a a '._.-""""-.  //            ");
		mvaddstr(row++, col, "           )=*=(    =\\T_= /    ~  ~  \\//            ");
		mvaddstr(row++, col, "          /     \\     `'`\\   ~   / ~  /             ");
		mvaddstr(row++, col, "          |     |         |~   \\ |  ~/               ");
		mvaddstr(row++, col, "         /| | | |\\         \\  ~/- \\ ~\\            ");
		mvaddstr(row++, col, "         \\| | |_|/|        || |  // /`               ");
		mvaddstr(row++, col, "  jgs_/\\_//_// __//\\_/\\_/\\_((_|\\((_//\\_/\\_/\\_ ");
		mvaddstr(row++, col, "  |  |  |  | \\_) |  |  |  |  |  |  |  |  |  |        ");
		mvaddstr(row++, col, "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |         ");
		mvaddstr(row++, col, "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |         ");
		mvaddstr(row++, col, "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |         ");
		mvaddstr(row++, col, "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |         ");
	}
	else if (story < 7) {

		mvaddstr(row++, col, "                                                       ");
		mvaddstr(row++, col, "            *      ,MMM8&&&.            *              ");
		mvaddstr(row++, col, "                  MMMM88&&&&&    .                     ");
		mvaddstr(row++, col, "                 MMMM88&&&&&&&                         ");
		mvaddstr(row++, col, "     *           MMM88&&&&&&&&                         ");
		mvaddstr(row++, col, "                 MMM88&&&&&&&&                         ");
		mvaddstr(row++, col, "                 'MMM88&&&&&&'                         ");
		mvaddstr(row++, col, "                   'MMM8&&&'      *                    ");
		mvaddstr(row++, col, "          |\\___/|     /\\___/\\                       ");
		mvaddstr(row++, col, "          )     (     )    ~( .              '         ");
		mvaddstr(row++, col, "         =\\     /=   =\\~    /=                       ");
		mvaddstr(row++, col, "           )===(       ) ~ (                           ");
		mvaddstr(row++, col, "          /     \\     /     \\                        ");
		mvaddstr(row++, col, "          |     |     ) ~   (                          ");
		mvaddstr(row++, col, "         /       \\   /     ~ \\                       ");
		mvaddstr(row++, col, "         \\       /   \\~     ~/                       ");
		mvaddstr(row++, col, "  jgs_/\\_/\\__  _/_/\\_/\\__~__/_/\\_/\\_/\\_/\\_/\\_ ");
		mvaddstr(row++, col, "  |  |  |  |( (  |  |  | ))  |  |  |  |  |  |          ");
		mvaddstr(row++, col, "  |  |  |  | ) ) |  |  |//|  |  |  |  |  |  |          ");
		mvaddstr(row++, col, "  |  |  |  |(_(  |  |  (( |  |  |  |  |  |  |          ");
		mvaddstr(row++, col, "  |  |  |  |  |  |  |  |\\)|  |  |  |  |  |  |         ");
		mvaddstr(row++, col, "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |          ");
	}
	else if (story < 9) {

		mvaddstr(row++, col, "                                                       ");
		mvaddstr(row++, col, "            *      ,MMM8&&&.            *              ");
		mvaddstr(row++, col, "                  MMMM88&&&&&    .                     ");
		mvaddstr(row++, col, "                 MMMM88&&&&&&&                         ");
		mvaddstr(row++, col, "     *           MMM88&&&&&&&&                         ");
		mvaddstr(row++, col, "                 MMM88&&&&&&&&                         ");
		mvaddstr(row++, col, "                 'MMM88&&&&&&'                         ");
		mvaddstr(row++, col, "                   'MMM8&&&'      *                    ");
		mvaddstr(row++, col, "           /\\/|_      __/\\                           ");
		mvaddstr(row++, col, "          /    -\\    /-   ~\\  .              '       ");
		mvaddstr(row++, col, "          \\    = Y =T_ =   /                          ");
		mvaddstr(row++, col, "           )==*(`     `) ~ \\                          ");
		mvaddstr(row++, col, "          /     \\     /     \\                        ");
		mvaddstr(row++, col, "          |     |     ) ~   (                          ");
		mvaddstr(row++, col, "         /       \\   /     ~ \\                       ");
		mvaddstr(row++, col, "         \\       /   \\~     ~/                       ");
		mvaddstr(row++, col, "  jgs_/\\_/\\__  _/_/\\_/\\__~__/_/\\_/\\_/\\_/\\_/\\_ ");
		mvaddstr(row++, col, "  |  |  |  | ) ) |  |  | ((  |  |  |  |  |  |          ");
		mvaddstr(row++, col, "  |  |  |  |( (  |  |  |  \\  |  |  |  |  |  |          ");
		mvaddstr(row++, col, "  |  |  |  | )_) |  |  |  |))|  |  |  |  |  |          ");
		mvaddstr(row++, col, "  |  |  |  |  |  |  |  |  (/ |  |  |  |  |  |          ");
		mvaddstr(row++, col, "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |          ");
	}
}

void NcursesMode::_draw_core_colums(DynamicData dynamicData) {

	float hight = HIGTH;
	float width = WIDTH;

	srand(clock());
	for (int i = _row / (hight / 2.17); i >= (_row / (hight / 2.17)) - (dynamicData.coreUsage[0] / 10); --i) {
		attron (COLOR_PAIR (4));
		mvprintw(i, _col / (width / 3.8), "#######");
		attroff (COLOR_PAIR (4));
	}
	for (int i = _row / (hight / 2.17); i >= (_row / (hight / 2.17)) - (dynamicData.coreUsage[1] / 10); --i) {
		attron (COLOR_PAIR (5));
		mvprintw(i, _col / (width / 4.1), "#######");
		attroff (COLOR_PAIR (5));
	}
	for (int i = _row / (hight / 2.17); i >= (_row / (hight / 2.17)) - (dynamicData.coreUsage[2] / 10); --i) {
		attron (COLOR_PAIR (6));
		mvprintw(i, _col / (width / 4.4), "#######");
		attroff (COLOR_PAIR (6));
	}
	for (int i = _row / (hight / 2.17); i >= (_row / (hight / 2.17)) - (dynamicData.coreUsage[3] / 10); --i) {
		attron (COLOR_PAIR (7));
		mvprintw(i, _col / (width / 4.7), "#######");
		attroff (COLOR_PAIR (7));
	}
}

void NcursesMode::_draw_2st_row(StaticData staticData) {

	float hight = HIGTH;
	float width = WIDTH;

	attron(COLOR_PAIR (8));
		mvprintw(_row / (hight / 2.49), _col / (width / 1.65), staticData.osName.data());
		mvprintw(_row / (hight / 2.69), _col / (width / 1.65), staticData.osVersion.data());
		mvprintw(_row / (hight / 2.89), _col / (width / 1.65), staticData.osBuild.data());
		mvprintw(_row / (hight / 3.09), _col / (width / 1.65), staticData.kernelVersion.data());
	attroff(COLOR_PAIR (8));
	attron(COLOR_PAIR (8));
		mvprintw(_row / (hight / 2.5), _col / (width / 2.9), staticData.userName.data());
		mvprintw(_row / (hight / 2.9), _col / (width / 2.9), staticData.hostName.data());
	attroff(COLOR_PAIR (8));
	attron(COLOR_PAIR (2));
		mvprintw(_row / (hight / 2.36), _col / (width / 1.4), "SYSTEM INFORMATION");
	attroff(COLOR_PAIR (2));
		attron(COLOR_PAIR (1));
		mvprintw(_row / (hight / 2.49), _col / (width / 1.15), "OS Name:");
		mvprintw(_row / (hight / 2.69), _col / (width / 1.15), "OS Version:");
		mvprintw(_row / (hight / 2.89), _col / (width / 1.15), "OS Build:");
		mvprintw(_row / (hight / 3.09), _col / (width / 1.15), "Kernel Version:");
		attroff(COLOR_PAIR (1));
	attron(COLOR_PAIR (2));
		mvprintw(_row / (hight / 2.36), _col / (width / 2.6), "ADMINISTRATIVE INFORMATION");
	attroff(COLOR_PAIR (2));
	attron(COLOR_PAIR (1));
		mvprintw(_row / (hight / 2.5), _col / (width / 2.4), "Username:");
		mvprintw(_row / (hight / 2.9), _col / (width / 2.4), "Hostname:");
	attroff(COLOR_PAIR (1));
	attron(COLOR_PAIR (2));
		mvprintw(_row / (hight / 2.36), _col / (width / 4.3), "CATS");
	attroff(COLOR_PAIR (2));
	
}

void NcursesMode::_draw_1st_row(DynamicData dynamicData) {

	float hight = HIGTH;
	float width = WIDTH;

	setlocale(LC_ALL, "");
	attron(COLOR_PAIR (2));
	mvprintw(_row / (10), _col / (width / 2.75), "DATE:");
    mvprintw(_row / (10), _col / (width / 3.1), dynamicData.currentTime);
	mvprintw(_row / (hight / 1.1), _col / (width / 1.5), "NETWORK");
	attroff(COLOR_PAIR (2));
		attron(COLOR_PAIR (1));
		mvprintw(_row / (hight / 1.3), _col / (width / 1.15), "Packets in:");
		mvprintw(_row / (hight / 1.6), _col / (width / 1.15), "Packets out:");
		attroff(COLOR_PAIR (1));
		attron(COLOR_PAIR (8));
		mvprintw(_row / (hight / 1.3), _col / (width / 1.65), dynamicData.netPacketsIn.data());
		mvprintw(_row / (hight / 1.6), _col / (width / 1.65), dynamicData.netPacketsOut.data());
		attroff(COLOR_PAIR (8));
	attron(COLOR_PAIR (2));
	mvprintw(_row / (hight / 1.1), _col / (width / 2.9), "RAM");
	attroff(COLOR_PAIR (2));
		attron(COLOR_PAIR (1));
		mvprintw(_row / (hight / 1.3), _col / (width / 2.4), "Total memory:");
		mvprintw(_row / (hight / 1.6), _col / (width / 2.4), "Used memory:");
		mvprintw(_row / (hight / 1.9), _col / (width / 2.4), "Free memory:");
		attroff(COLOR_PAIR (1));
		attron(COLOR_PAIR (8));
		mvprintw(_row / (hight / 1.3), _col / (width / 3), "%i", dynamicData.totalRAM);
		mvprintw(_row / (hight / 1.3), _col / (width / 3.2), "MB");
		mvprintw(_row / (hight / 1.6), _col / (width / 3), "%i", dynamicData.usedRAM);
		mvprintw(_row / (hight / 1.6), _col / (width / 3.2), "MB");
		mvprintw(_row / (hight / 1.9), _col / (width / 3), "%i", dynamicData.freeRAM);
		mvprintw(_row / (hight / 1.9), _col / (width / 3.2), "MB");
		attroff(COLOR_PAIR (8));
	attron(COLOR_PAIR (2));
	mvprintw(_row / (hight / 1.1), _col / (width / 4.3), "CPU");
	attroff(COLOR_PAIR (2));
		attron(COLOR_PAIR (1));
		mvprintw(_row / (hight / 1.3), _col / (width / 3.8), "Core 1");
		mvprintw(_row / (hight / 1.3), _col / (width / 4.1), "Core 2");
		mvprintw(_row / (hight / 1.3), _col / (width / 4.4), "Core 3");
		mvprintw(_row / (hight / 1.3), _col / (width / 4.7), "Core 4");
		attroff(COLOR_PAIR (1));
		attron(COLOR_PAIR (8));
		mvprintw(_row / (hight / 1.45), _col / (width / 3.83), "%.2f%%", dynamicData.coreUsage[0]);
		mvprintw(_row / (hight / 1.45), _col / (width / 4.13), "%.2f%%", dynamicData.coreUsage[1]);
		mvprintw(_row / (hight / 1.45), _col / (width / 4.43), "%.2f%%", dynamicData.coreUsage[2]);
		mvprintw(_row / (hight / 1.45), _col / (width / 4.73), "%.2f%%", dynamicData.coreUsage[3]);
		attroff(COLOR_PAIR (8));
		_draw_core_colums(dynamicData);
}

void NcursesMode::draw(StaticData staticData, DynamicData dynamicData) {
	if (this->_story == 10) {
		this->_story = -1;
	}
	this->_story++;
	
	getmaxyx(stdscr, this->_row, this->_col);
	
	_draw_1st_row(dynamicData);
	_draw_2st_row(staticData);
	_drawing_blocks(this->_story);
}
