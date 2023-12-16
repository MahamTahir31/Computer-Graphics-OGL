

#pragma once

class Point2
{
public:
	Point2() { x = y = 0.0f; } // constructor 1
	Point2(float xx, float yy) { x = xx; y = yy; } // constructor 2
	void set(float xx, float yy) { x = xx; y = yy; }
	float getX() { return x; }
	float getY() { return y; }
	void draw(void)
	{
		glPointSize(2.0);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
		glEnable(GL_POINT_SMOOTH);

		glBegin(GL_POINTS); // draw this point
		glVertex2f((GLfloat)x, (GLfloat)y);
		glEnd();

		glDisable(GL_POINT_SMOOTH);

	}// end draw
private:
	float x, y;
}; // end class Point2

class Spider
{
private:
	enum State { DIE } state;
	RGBApixmap pix[2];
	float pos_X, pos_Y;

public:
	bool is_moving;	// indicate the spider is still alive
	float sspeed;
	float theta;
	float rate_tChange;
	Spider();
	Spider(Point2 pos);
	void setPosition(float x, float y);
	float spider_getX();
	float spider_getY();
	void changePosition(float dx, float dy);
	void render();
};


///////////////////////////SPider///////////////////////////////////////
Spider::Spider()
{

}
Spider::Spider(Point2 pos)
{


	this->pos_X = 0.0;
	this->pos_Y = 0.0;
	this->is_moving = true;
	pix[0].readBMPFile("spider.bmp");
	pix[1].readBMPFile("splash.bmp");
	//pix[i].readBMPFile(fname[i],0);
	//pix[i]. setChromaKey(192,192,192);


}
void Spider::setPosition(float x, float y)
{
	pos_X = x;
	pos_Y = y;
	//sets pos_X to x and pos_Y to y
}
float Spider::spider_getX()
{
	return pos_X;
}
float Spider::spider_getY()
{
	return pos_Y;
}
void Spider::changePosition(float dx, float dy)
{
	pos_X += dx;
	pos_Y += dy;
	//ADD dx and dy in pos_X and pos_Y
}
void Spider::render()
{

	if (this->is_moving == true)

	{
		glRasterPos2i(this->pos_X, this->pos_Y);
		pix[0].mDraw();//load pic
	}

	else
	{
		pix[1].mDraw();
	}


}