/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesMode.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 15:20:43 by hdanylev          #+#    #+#             */
/*   Updated: 2018/07/01 19:59:58 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIS_NCURSES_HPP
# define VIS_NCURSES_HPP

# include <iostream>
# include <unistd.h>
# include <time.h>
# include <sys/utsname.h>
# include <ncurses.h>
# include <sys/types.h>
# include <sys/sysctl.h>
# include "IMonitorDisplay.class.hpp"

# define HIGTH 4
# define WIDTH 6

class NcursesMode: public IMonitorDisplay {

	private:
		int _row;
		int _col;
		int _story;

		void _cats(float row, float col, int story);
		void _draw_2st_row(StaticData staticData);
		void _draw_1st_row(DynamicData dynamicData);
		void _drawing_blocks(int story);
		void _draw_core_colums(DynamicData dynamicData);

	public:
		NcursesMode();
		NcursesMode(NcursesMode const &ref);	
		~NcursesMode();

		NcursesMode &operator=(NcursesMode const &ref);

		void draw(StaticData staticData, DynamicData dynamicData);

		int getRow() const;
		int getCol() const;

};

#endif