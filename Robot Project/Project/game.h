#ifndef game_H
#define game_H
#include "robot.h"
#include<string>
#include<vector>
#include<map>
#include<algorithm>

class game {

	std::map<std::string, robot> robots;
public:
	game();
	
	int num_robots() const;
	void move(const std::string &name, int dir);
	int num_close() const;
	int max_distance() const;
	std::string furthest() const;
	std::vector<robot> robots_by_travelled() const;
};

bool compareTravelDistance(const robot &robot1, const robot &robot2);
#endif 