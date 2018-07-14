# include "iGraphics.h"

/* 
 Project : DX-Ball
 By
 Sufian
 ID:011132129.
*/

double ax,ay,cx,cy,dx,dy;
int flagx,flagy;
int isVisible[100][100];
int count=0;
char text[5];
int page =1;


void check_fault()
{
	if(cy <= 35)
	{
		if(cx > dx+100+10 || cx < dx-10)
			page = 2;
	}
}

void brick_draw()
{
	for(int r=400,int di=0; r>=200;r=r-15,di++)
	{
		ay=r;
		for(int c=0,int dj=0;c<=650; c=c+50,dj++)               /*BRIC DRAWING CODES*/
		{
			ax=c;
			c=c+4;
			if(cy>=r-15 && cy<=r && cx>=c && cx<=c+50)          /*COLLISION CHECK*/
			{
				if(isVisible[di][dj]==1)
				{
					isVisible[di][dj]=0;
					flagy*=-1;
					count+=1;
				}
			}
				if(isVisible[di][dj]==1)
			       iFilledRectangle(ax,ay,50,15);
           iSetColor(0,255,0);
		}
		r=r-4;
	
	}


}
void iDraw()
{
	//place your drawing codes here	
	iClear();

	if(page == 1)
	{
		
		iSetColor(0,255,0);
		iFilledCircle(cx,cy,10);
		iFilledRectangle(dx,dy,100,20);
		brick_draw();
		iText(255,440,"Score : ",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(350,440,text,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(page == 2)
	{
			iShowBMP(130,200,"Endgame.bmp");
			iText(265,170,"Your Scores : ",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(405,170,text,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	

}

/* 
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx,  my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my)  is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	/*if(key == 's' && page==2)
	{
		page=3;
	
	}*/
	//place your codes for other keys here
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like- function keys, home, end, pg up, pg down, arraows etc. you have to use appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT  */

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if(key == GLUT_KEY_RIGHT)                              /*KEY-CONTROL*/
	{
		if(dx < 600)
			dx += 20;
	}
		if(key == GLUT_KEY_LEFT)
	{
		if(dx > 0)
			dx -= 20;
	}

		//place your codes for other keys here
}
void position_change()
{
	
	cx += flagx*5;
	cy += flagy*5;
	if(cx>685)
		flagx = -1;
	else if (cx<15)                                        /*BALL MOVEMENT*/
		flagx = 1;

	if(cy>385)
		flagy = -1;
	else if(cy<35)
	    flagy = 1;

	check_fault();		

			
}

void score()
{
	if(count>0)
		sprintf(text,"%d",count);                          /*SCORE COUNT*/
	else
	{
		text[0]='0';
		text[1]='\0';
	}

}


int main()
{
	//place your own initialization codes here. 
	for(int p=0;p<10;p++)
		for(int q=0;q<13;q++) 
		{
			isVisible[p][q]=1;
		}
	dx=0;
	dy=0;
	cx=50;
	cy=50;
	ax=0;
	ay=380;
	flagx=1;flagy=1;
	iSetTimer(35,position_change);
	iSetTimer(35,score);
	iInitialize(700, 480, "DX-Ball");
	return 0;
}
