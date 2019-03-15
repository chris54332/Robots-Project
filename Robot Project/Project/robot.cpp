#include "robot.h"
#include<cstdlib>
#include<string>

using namespace std;



	 robot::robot(const string &n)
	{
		robot_name = n;
		x = 0;
		y = 0;
		total_distance = 0; 
	}
	const string & robot::name() const {
		return robot_name;
	}
	int robot::north() const {
		return y;
	}
	int robot::east() const {
		return x;
	}
	int robot::travelled() const {
		return total_distance;
	}
	void robot::move_north() {
		y += 1;
		total_distance++;
	}
	void robot::move_east() {
		x += 1;
		total_distance++;
	}
	void robot::move_south() {
		y -= 1;
		total_distance++;
	}
	void robot::move_west() {

		x -= 1;
		total_distance++;
	}
int distance(const robot &r)
{
	return( abs(r.east()) + abs(r.north()));
}