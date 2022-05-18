#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <GLUT/glut.h>
#include<time.h>
#define PI 3.1415927
#define SPEED 30.0
void rock();
void display1();
void display2();
void display3();
void ship();
void water();

GLint a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 500, h = 600, x = 0, i = 0;
int first = 1;
float m=0.0;
GLfloat theta = 0.0;
int to_plus = 10;
void update(int value)
{
    
    if(first==0)
    to_plus/=2;
    m += to_plus;
    a += to_plus;
    glutPostRedisplay();
    glutTimerFunc(200, update, 0);
}
void declare(char *string)
{
     while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}

void display() //Implementing Animation
{
    glClear(GL_COLOR_BUFFER_BIT); //Buffer clearing
    display1();
    if (a > 950)
    {
        if(first){ m = 0; first = 0;}
    b += 20;
    display2();
    }
    if (b > 80)
    {
    c += 10;
    display3();
    }
    glFlush();
    glutSwapBuffers();
}

void draw_pixel(GLint cx, GLint cy)
{

    glBegin(GL_POINTS);
    glVertex2i(cx,cy);
    glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
    draw_pixel(x+h,y+k);
    draw_pixel(-x+h,y+k);
    draw_pixel(x+h,-y+k);
    draw_pixel(-x+h,-y+k);
    draw_pixel(y+h,x+k);
    draw_pixel(-y+h,x+k);
    draw_pixel(y+h,-x+k);
    draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
    GLint d=1-r, x=0, y=r;
    while(y>x)
    {
        plotpixels(h,k,x,y);
        if(d<0) d+=2*x+3;
        else
        {
            d+=2*(x-y)+5;
            --y;
        }
        ++x;
    }
    plotpixels(h,k,x,y);
}
int sun=50;
void draw_object()
{
    int l;
    //sun


        for(l=0;l<=sun;l++)
    {
            glColor3f(1.0,0.9,0.0);
            draw_circle(100,625,l);
    }


//cloud1


    for(l=0;l<=20;l++)
    {
        glColor3f(0.0,1.0,1.0);
        draw_circle(160+m,625,l);
    }


    for(l=0;l<=35;l++)
    {
        glColor3f(0.0,1.0,1.0);
        draw_circle(200+m,625,l);
        draw_circle(225+m,625,l);
    }

    for(l=0;l<=20;l++)
    {
        glColor3f(0.0,1.0,1.0);
        draw_circle(265+m,625,l);
    }

//cloud2


    for(l=0;l<=20;l++)
    {
        glColor3f(0.0,1.0,1.0);
        draw_circle(370+m,615,l);
}




    for(l=0;l<=35;l++)
    {

        glColor3f(0.0,1.0,1.0);
        draw_circle(410+m,615,l);
        draw_circle(435+m,615,l);
        draw_circle(470+m,615,l);
    }

    for(l=0;l<=20;l++)
        {
            glColor3f(0.0,1.0,1.0);
            draw_circle(500+m,615,l);
    }
// cloud 3
    
    for(l=0;l<=20;l++)
    {
        glColor3f(0.0,1.0,1.0);
        draw_circle(580+m,625,l);
}




    for(l=0;l<=35;l++)
    {

        glColor3f(0.0,1.0,1.0);
        draw_circle(620+m,625,l);
        draw_circle(645+m,625,l);
        draw_circle(680+m,625,l);
    }

    for(l=0;l<=20;l++)
        {
            glColor3f(0.0,1.0,1.0);
            draw_circle(710+m,625,l);
    }

}


        
void display1() //Animation of moving ship in water without rock
{
    glPushMatrix();
    glTranslated(a, 75, 0.0); //Matrix transformation x,y,z dimensions
    ship();
    glPopMatrix();
    water();
    draw_object();
}

void display2() //Animation of ship moving with rock in between
{
    glClear(GL_COLOR_BUFFER_BIT);
    rock();
    glPushMatrix();
    glTranslated(b, 75, 0.0);
    ship();
    glPopMatrix();
    water();
    draw_object();
}

void display3() //Animation of Sinking ship including collision
{
    glClear(GL_COLOR_BUFFER_BIT);
    x -= 1;
    rock();
    glPushMatrix();
    glTranslated(c, 100 + x * 5, 0.0);
    glRotated(-15, 0, 0, 1);
    ship();
    glPopMatrix();
    water();
    draw_object();
}

void water() //Add water
{
    glColor3f(0.196078, 0.6, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(1000, 0);
    glVertex2f(1000, 100);
    glVertex2f(0, 100);
    glEnd();
}

void ship() //Add ship
    {
    glScaled(24, 24, 0);
    glColor3f(0, 0.4, 0.2); //base
    glBegin(GL_POLYGON);
    glVertex2f(0.5, 5.0);
    glVertex2f(3, 1);
    glVertex2f(22, 1);
    glVertex2f(24.0, 5.0);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glRasterPos2f(13,2);
    declare("INDIA ");
    glColor3f(1.0, 1.0, 1.0); //ring
    glBegin(GL_POLYGON);
    glVertex2f(1.35, 3.5);
    glVertex2f(1.6, 3.2);
    glVertex2f(23.2, 3.2);
    glVertex2f(23.35, 3.5);
    glEnd();
    glColor3f(0.3, 0, 0.1); //base
    glBegin(GL_POLYGON);
    glVertex2f(21.0, 5.0);
    glVertex2f(21.0, 6.0);
    glVertex2f(24.5, 6.0);
    glVertex2f(24.0, 5.0);
    glEnd();
    glColor3f(0.74902, 0.847059, 0.847059); //top-mid
    glBegin(GL_POLYGON);
    glVertex2f(2.0, 5.0);
    glVertex2f(2.0, 12.0);
    glVertex2f(15.0, 12.0);
    glVertex2f(19.5, 5.0);
    glEnd();
    glColor3f(0.137255, 0.137255, 0.556863); //ring
    glBegin(GL_POLYGON);
    glVertex2f(2.0, 8.2);
    glVertex2f(2.0, 8.8);
    glVertex2f(17.1, 8.8);
    glVertex2f(17.5, 8.2);
    glEnd();
    glColor3f(1, 1, 1); //window
    glBegin(GL_POLYGON);
    glVertex2f(3.0, 6.0);
    glVertex2f(3.0, 7.2);
    glVertex2f(4.0, 7.2);
    glVertex2f(4.0, 6.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(4.7, 6.0);
    glVertex2f(4.7, 7.2);
    glVertex2f(5.7, 7.2);
    glVertex2f(5.7, 6.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(8.1, 6.0);
    glVertex2f(8.1, 7.2);
    glVertex2f(9.1, 7.2);
    glVertex2f(9.1, 6.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(9.8, 6.0);
    glVertex2f(9.8, 7.2);
    glVertex2f(10.8, 7.2);
    glVertex2f(10.8, 6.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(6.4, 6.0);
    glVertex2f(6.4, 7.2);
    glVertex2f(7.4, 7.2);
    glVertex2f(7.4, 6.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(11.5, 6.0);
    glVertex2f(11.5, 7.2);
    glVertex2f(12.5, 7.2);
    glVertex2f(12.5, 6.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(13.3, 6.0);
    glVertex2f(13.3, 7.2);
    glVertex2f(14.3, 7.2);
    glVertex2f(14.3, 6.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(15.1, 6.0);
    glVertex2f(15.1, 7.2);
    glVertex2f(16.1, 7.2);
    glVertex2f(16.1, 6.0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(16.9, 6.0);
    glVertex2f(16.9, 7.2);
    glVertex2f(17.9, 7.2);
    glVertex2f(17.9, 6.0);
    glEnd();
    glColor3f(1, 1, 1); //window
    glBegin(GL_POLYGON);
    glVertex2f(3.0, 9.8);
    glVertex2f(3.0, 11.0);
    glVertex2f(4.0, 11.0);
    glVertex2f(4.0, 9.8);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(4.7, 9.8);
    glVertex2f(4.7, 11.0);
    glVertex2f(5.7, 11.0);
    glVertex2f(5.7, 9.8);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(8.1, 9.8);
    glVertex2f(8.1, 11.0);
    glVertex2f(9.1, 11.0);
    glVertex2f(9.1, 9.8);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(9.8, 9.8);
    glVertex2f(9.8, 11.0);
    glVertex2f(10.8, 11.0);
    glVertex2f(10.8, 9.8);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(6.4, 9.8);
    glVertex2f(6.4, 11.0);
    glVertex2f(7.4, 11.0);
    glVertex2f(7.4, 9.8);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(11.5, 9.8);
    glVertex2f(11.5, 11.0);
    glVertex2f(12.5, 11.0);
    glVertex2f(12.5, 9.8);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(13.3, 9.8);
    glVertex2f(13.3, 11.0);
    glVertex2f(14.3, 11.0);
    glVertex2f(14.3, 9.8);
    glEnd();
    glColor3f(1, 0.6, 0); //top-cover
    glBegin(GL_POLYGON);
    glVertex2f(1.5, 12.0);
    glVertex2f(1.5, 12.5);
    glVertex2f(16.0, 12.5);
    glVertex2f(16.0, 12.0);
    glEnd();
    glColor3f(1, 0.6, 0); //chim
    glBegin(GL_POLYGON);
    glVertex2f(2.5, 12.5);
    glVertex2f(2.5, 16.0);
    glVertex2f(5.0, 16.0);
    glVertex2f(5.0, 12.5);
    glEnd();
    glColor3f(1.0, 0.25, 0.0); //ring
    glBegin(GL_POLYGON);
    glVertex2f(2.5, 12.5);
    glVertex2f(2.5, 13.5);
    glVertex2f(5.0, 13.5);
    glVertex2f(5.0, 12.5);
    glEnd();
    glColor3f(1.0, 0.25, 0.0); //ring
    glBegin(GL_POLYGON);
    glVertex2f(2.5, 14.5);
    glVertex2f(2.5, 15.5);
    glVertex2f(5.0, 15.5);
    glVertex2f(5.0, 14.5);
    glEnd();
    glColor3f(1, 0.6, 0); //chim
    glBegin(GL_POLYGON);
    glVertex2f(6.0, 12.5);
    glVertex2f(6.0, 16.0);
    glVertex2f(8.5, 16.0);
    glVertex2f(8.5, 12.5);
    glEnd();
    glColor3f(1.0, 0.25, 0.0); //ring
    glBegin(GL_POLYGON);
    glVertex2f(6.0, 14.5);
    glVertex2f(6.0, 15.5);
    glVertex2f(8.5, 15.5);
    glVertex2f(8.5, 14.5);
    glEnd();
    glColor3f(1.0, 0.25, 0.0); //ring
    glBegin(GL_POLYGON);
    glVertex2f(6.0, 12.5);
    glVertex2f(6.0, 13.5);
    glVertex2f(8.5, 13.5);
    glVertex2f(8.5, 12.5);
    glEnd();
}

void rock() {
    glPushMatrix();
    glTranslated(450, 50, 0.0);
    glScaled(10, 10, 0);
    glColor3f(0.36, 0.25, 0.20);
    if (c > 0) {
        glPushMatrix();
        glTranslated(0, x, 0);
        glPushMatrix();
        glTranslated(7, 2, 0.0);
        glRotated(-x, 0, 0, 1);
        glTranslated(-7, -2, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(8.1, 1);
        glVertex2f(7.89, 1.23);
        glVertex2f(11.26, 18);
        glVertex2f(13.23, 21.33);
        glVertex2f(14.23, 2.53);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glTranslated(12, 3, 0.0);
        glRotated(x, 0, 0, 1);
        glTranslated(-12, -3, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(11.1, 3.5);
        glVertex2f(13.2, 18.7);
        glVertex2f(16.4, 18.5);
        glVertex2f(18.12, 3.65);
        glVertex2f(19.21, 1.25);
        glEnd();
        glPopMatrix();
        glPopMatrix();
        
     
    }
    else
    {
        glBegin(GL_POLYGON);
        glVertex2f(8.1, 1);
        glVertex2f(7.89, 1.23);
        glVertex2f(11.26, 18);
        glVertex2f(13.23, 21.33);
        glVertex2f(14.23, 2.53);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(11.1, 3.5);
        glVertex2f(13.2, 18.7);
        glVertex2f(16.4, 18.5);
        glVertex2f(18.12, 3.65);
        glVertex2f(19.21, 1.25);
        glEnd();
        glColor3f(0.435294,0.258824,0.258824);
    glBegin(GL_POLYGON);
    glVertex2f(10,20);
    glVertex2f(10,24);
    glVertex2f(30.6,24);
    glVertex2f(30.6,20);
    glEnd();

    }
    glPopMatrix();
}
void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {
case 'f':
    case 'F':
        to_plus+=3;
        break;

    case 's':
case 'S':
        to_plus-=3;
        if(to_plus<0)
        to_plus=0;
        break;
case 'b':
    case 'B':
        sun+=10;
        break;
case 't':
    case 'T':
        sun-=10;
        if(sun<10)
        sun=10;
        break;
    };

}
void myinit()
{
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glColor3f(1.0, 0.0, 0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 999.0, 0.0, 799.0);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1024.0, 768.0);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Sinking Ship - CG Project");
    glutKeyboardFunc(keyboardFunc);
    glutDisplayFunc(display);
//    glutIdleFunc(idle);
    myinit();
    glutTimerFunc(100, update, 0);
    glutMainLoop();
    return 0;
}

