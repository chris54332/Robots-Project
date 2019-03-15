#ifndef robot_H
#define robot_H


#include<string>
	
class robot
{
	int x, y; //The axes on which the robot travels
	std::string robot_name;
	int total_distance; //The total distance travelled by the robot
	int direction // The direction the robot is facing
public:
	explicit robot(const std::string &n);
	
	const std::string & name() const;
	int north() const;
	int east() const;
	int travelled() const;
	int direction() const;
	void move_north();
	void move_east();
	void move_south();
	void move_west();
	void rotate_left();
	void rotate_right();
};
int distance(const robot &r);
#endif 
