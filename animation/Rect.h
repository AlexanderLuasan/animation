#pragma once
class poly
{
public:
	poly();
	void add(int x,int y);
	int getx(int i);
	int gety(int i);
	void setxypos(int x, int y);
	int getxpos();
	int getypos();
	int getindex();
private:
	int xpos, ypos;
	int index;
	int points[10][2];
};

class point
{
public:
	point();
	point(int x, int y);
	void setx(int x);
	void sety(int y);
	int getx();
	int gety();
private:
	int xpos, ypos;
};
class rect
{
public:
	rect(int x, int y, int w, int h);//iniate with all fields
	rect(); //defult make
	void display();//prints the varibles for esasy viewing
	
	//colision
	bool colision(point other);
	bool colision(rect other,int offsetx, int offsety);
	bool colision(rect other);//uses other colision functions to detect overlap
	bool verticalOverLap(rect other,int y);
	bool horizantalOverLap(rect other,int x);
	bool verticalOverLap(rect other);
	bool horizantalOverLap(rect other);


	//advanced setting and getting


	int* getCenter(); // returns center of shape rounded down
	int getCenterx();
	int getCentery();
	void setCenter(int x,int y); // sets center 
	int left();	//give the x value of left edge
	void left(int l); //sets x value of left edge
	int right(); // sets x value of right edge
	void right(int r);
	int top();
	void top(int t);
	int bottom();
	void bottom(int b);
	//basic setting and getting these replace the core variables
	int getx();
	int gety();
	int getw();
	int geth();
	void setx(int x);
	void sety(int y);
	void setw(int w);
	void seth(int h);


private:
	int xpos, ypos, width, height;
};

