#include "game.h"
#include "robot.h"
#include<cstdlib>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

	game::game() {
		
	}
	
	int game::num_robots() const{
		return game::robots.size();
			
	}
	int game::num_close() const{
		int robot_num=0;
		map<string, robot>::const_iterator itr;
		for (itr = robots.begin(); itr != robots.end(); ++itr) {
			if (distance(itr->second) <= 10) {
				robot_num += 1;
			}
		}
		return robot_num;
	}
	void game::move(const string &name, int dir) {


		if (game::robots.count(name) == 1)
		{
			
			if (dir == 0) 
				game::robots.at(name).move_north();
			else if (dir == 1)
				game::robots.at(name).move_east();
			else if (dir == 2)
				game::robots.at(name).move_south();
			else if (dir == 3)
				game::robots.at(name).move_west();


		}
		else

		{
			robot robot(name);
			game::robots.emplace(name, robot);
			if (dir == 0)
				game::robots.at(name).move_north();
			else if (dir == 1)
				game::robots.at(name).move_east();
			else if (dir == 2)
				game::robots.at(name).move_south();
			else if (dir == 3)
				game::robots.at(name).move_west();

		}
	}

	int game::max_distance() const{
		int max_distance = distance(robots.begin()->second);
		map<string, robot>::const_iterator itr;
		for (itr = robots.begin(); itr != robots.end(); ++itr) {
			if (max_distance<distance(itr->second)) {
				max_distance = distance(itr->second);
			}
		}
		return max_distance;
	}
	string game::furthest() const{
		int furthest_distance = distance(robots.begin()->second);
		string furthest_robot;
		map<string, robot>::const_iterator itr;
		for (itr = robots.begin(); itr != robots.end(); ++itr) {
			if (furthest_distance < distance(itr->second)) {
				furthest_distance = distance(itr->second);
				furthest_robot = itr->second.name();
			}
		}
		return furthest_robot;
	}
	
	bool compareTravelDistance(const robot &robot1, const robot &robot2)
	{
		return (robot1.travelled() < robot2.travelled());
	}
	
	vector<robot> game::robots_by_travelled() const{
		vector<robot> sorted_vector_robots;
		map<string, robot>::const_iterator itr;
		for (itr = robots.begin(); itr != robots.end(); ++itr) {
			sorted_vector_robots.push_back(itr->second);
		}
		//sorting the vector by distance traveled in ascending order
		sort(sorted_vector_robots.begin(), sorted_vector_robots.end(), compareTravelDistance);
		return sorted_vector_robots;
	}
	