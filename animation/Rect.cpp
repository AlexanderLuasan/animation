#include "Rect.h"
#include <iostream>
using namespace std;
rect::rect(int x, int y, int w, int h){
	xpos = x;
	ypos = y;
	width = w;
	height = h;

}
rect::rect() {
	xpos = 0;
	ypos = 0;
	width = 10;
	height = 10;
}

void rect::display() {
	cout << "ypos  :" << this->gety() << endl;
	cout << "xpos  :" << this->getx() << endl;
	cout << "height:" << this->geth() << endl;
	cout << "width :" << this->getw() << endl;
}


bool rect::colision(point other)
{
	if (this->left() < other.getx() && other.getx() < this->right()) {
		if (this->top() < other.gety() && other.gety() < this->bottom()) {
			return true;
		}
	}
	return false;
}

bool rect::colision(rect other, int offsetx, int offsety)
{
	if ((this->horizantalOverLap(other)) &(this->verticalOverLap(other))) {
		return true;
	}
	else {
		return false;
	}
}

bool rect::colision(rect other) {
	if ((this->horizantalOverLap(other)) &( this->verticalOverLap(other))) {
		return true;
	}
	else {
		return false;
	}
}

bool rect::verticalOverLap(rect other, int y)
{
	if ((this->top() < other.bottom()+y) & (this->bottom() > other.top()+y)) {
		return true;
	}
	else if ((this->top() > other.bottom()+y)&(this->bottom() < other.top()+y)) {
		return true;
	}
	else {
		return false;
	}
}

bool rect::horizantalOverLap(rect other, int x)
{
	if ((this->left() < other.right()+x) & (this->right() > other.left()+x)) {
		return true;
	}
	else if ((this->left() > other.right()+x) & (this->right() < other.left()+x)) {
		return true;
	}
	else {
		return false;
	}
}


bool rect::horizantalOverLap(rect other) {
	if ((this->left() < other.right()) & (this->right() > other.left())) {
		return true;
	}
	else if ((this->left() > other.right()) & (this->right() < other.left())) {
		return true;
	}
	else {
		return false;
	}
}

bool rect::verticalOverLap(rect other) {
	if ((this->top() < other.bottom()) & (this->bottom() > other.top())) {
		return true;
	}
	else if ((this->top() > other.bottom() )&( this->bottom() < other.top())) {
		return true;
	}
	else {
		return false;
	}
}






int* rect::getCenter() {
	int end[2];
	end[0] = this->getx() + this->getw() / 2;
	end[1] = this->gety() + this->geth() / 2;

	return end;
}
int rect::getCenterx()
{
	return this->getx()+this->getw()/2;
}
int rect::getCentery()
{
	return this->gety()+this->geth()/2;
}
void rect::setCenter(int x,int y) {
	this->setx(x - this->getw()/2);
	this->sety(y - this->geth()/2);


}

int rect::left() {
	return xpos;
}
void rect::left(int l) {
	this->setx(l);
}

int rect::right() {
	return xpos+width;
}
void rect::right(int r) {
	this->setx(r-width);
}

int rect::top() {
	return ypos;
}
void rect::top(int t) {
	this->sety(t);
}

int rect::bottom() {
	return ypos + height;
}
void rect::bottom(int b) {
	this->sety(b-height);
}


//getter and setters
int rect::getx() {
	return xpos;
}

int rect::gety() {
	return ypos;
}

int rect::getw() {
	return width;
}

int rect::geth() {
	return height;
}

void rect::setx(int x) {
	xpos = x;
}

void rect::sety(int y) {
	ypos = y;
}

void rect::seth(int h) {
	height = h;
}

void rect::setw(int w) {
	width = w;
}

poly::poly()
{
	index = 0;
}

void poly::add(int x, int y)
{
	points[index][0] = x;
	points[index][1] = y;
	index += 1;
}

int poly::getx(int i)
{
	return points[i][0];
}

int poly::gety(int i)
{
	return points[i][1];
}

void poly::setxypos(int x, int y)
{
	xpos = x;
	ypos = y;
}

int poly::getxpos()
{
	return xpos;
}

int poly::getypos()
{
	return ypos;
}

int poly::getindex()
{
	return index;
}

point::point()
{
	xpos = 0;
	ypos = 0;
}

point::point(int x, int y)
{
	xpos = x;
	ypos = y;

}

void point::setx(int x)
{
	xpos = x;
}

void point::sety(int y)
{
	ypos = y;
}

int point::getx()
{
	return xpos;
}

int point::gety()
{
	return ypos;
}


