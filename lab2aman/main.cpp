#ifdef __APPLE__
#include <GLUT/glut.h>   //library call
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <cmath>
#include <stdlib.h>
//
#include "RGBpixmap.cpp"
RGBpixmap pix[10];
void cube();
void cube2();
int a1=0;
int a2=0;
int aa3=0;
double zoom = 1;
double tx = 0;
double ty = 0;
double tz = 0;


float PI =3.1416;
static GLdouble camRadius = 10;
float eyex=0,eyey=0,eyez=10,cdx=0,cdy=0,cdz=0,hdx=0,hdy=2,hdz=0;
float angle=0.0;
int check=0;
float winW,winH;


const GLfloat light_ambient[]  = { .3f, .3f, .3f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 2.0f, 0.0f };

const GLfloat light_position_spot[] = { 2.0f, 3.0f, -5.0f, 1.0f };
const GLfloat spot_direction[]= {-2.0,-2.0,-5.0};

const GLfloat no_light[] = {0.0f,0.0f,0.0f,1.0f};

const GLfloat light_ambient_3[]  = { .5f, .5f, .5f, 1.0f };
const GLfloat light_diffuse_3[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular_3[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position_3[] = { 2.0f, 5.0f, 2.0f, 0.0f };


void ownscaled(GLfloat sx,GLfloat sy, GLfloat sz)
{
    GLfloat scaled[16]= {sx,0,0,0,
                         0,sy,0,0,
                         0,0,sz,0,
                         0,0,0,1
                        };
    glMatrixMode(GL_MATRIX_MODE);
    glMultMatrixf(scaled);
}

void pakha();


void righthalfcircle(float orx,float orz)
{
    float radius = .5;
    float twoPI = 2 * PI;



    GLfloat mat_ambient[]    = { .2f, .2f, .2f, 1.0f };
    GLfloat mat_diffuse[]    = { 1.0f, 1.0f, 0.2f, 1.0f };
    GLfloat mat_specular[]   = { 1.0f, 1.0f, 0.2f, 1.0f };
    GLfloat high_shininess[] = { 100.0f };

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


    glBegin(GL_TRIANGLE_FAN);

    for (float i = 0.0; i <= twoPI / 2; i += 0.001)
        glVertex3f((orx+sin(i)*radius), (orz+cos(i)*radius),-13);

    glEnd();
    glFlush();
}


void drawLeftCircle(float orx,float orz)
{
    float radius = .5;
    float twoPI = 2 * PI;


    GLfloat mat_ambient[]    = { .21f, .21f, .21f, 1.0f };
    GLfloat mat_diffuse[]    = { 1.0f, 1.0f, 0.2f, 1.0f };
    GLfloat mat_specular[]   = { 1.0f, 1.0f, 0.2f, 1.0f };
    GLfloat high_shininess[] = { 100.0f };

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glBegin(GL_TRIANGLE_FAN);


    for (float i = PI; i <= twoPI; i += 0.001)
        glVertex3f((orx+sin(i)*radius), (orz+cos(i)*radius),-13);
    glEnd();
    glFlush();
}


void init()
{
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();


    glTranslated(1.5,-10.5,-13);
    glRotatef(0.0, 0.0, 1.0, 0.0);

    gluCylinder(quadratic,.1,.1,3.0f,32,32);
}

void helicopter()
{


    GLfloat mat_ambient[]    = { .4f, .4f, .4f, 1.0f };
    GLfloat mat_diffuse[]    = { 10.0f, 10.0f, 0.2f, 1.0f };
    GLfloat mat_specular[]   = { 1.0f, 1.0f, 0.2f, 1.0f };
    GLfloat high_shininess[] = { 100.0f };

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);




    glBegin(GL_QUADS);
////////////////first portion//////////////////
    // glColor3d(1,1,0);
    glVertex3f(9,5,3);
    glVertex3f(12,5,3);
    glVertex3f(12,11,3);
    glVertex3f(9,10,3);

    // glColor3d(0,1,0);
    glVertex3f(12,5,3);
    glVertex3f(12,5,0);
    glVertex3f(12,11,0);
    glVertex3f(12,11,3);

    // glColor3d(1,1,0);
    glVertex3f(9,5,0);
    glVertex3f(9,10,0);
    glVertex3f(12,11,0);
    glVertex3f(12,5,0);

    //glColor3d(0,1,1);
    glVertex3f(9,5,0);
    glVertex3f(9,5,3);
    glVertex3f(9,10,3);
    glVertex3f(9,10,0);



    // glColor3d(1,0,0);
    glVertex3f(9,5,0);
    glVertex3f(12,5,0);
    glVertex3f(12,5,3);
    glVertex3f(9,5,3);

    glEnd();





////////////////////second porton///////////////////////
    glBegin(GL_QUADS);
    //glColor3d(1,.5,0);
    glVertex3f(5,5,3);
    glVertex3f(9,5,3);
    glVertex3f(9,10,3);
    glVertex3f(5,7,3);


    mat_ambient[0]=.4,mat_ambient[1]=.4,mat_ambient[2]=.4,mat_ambient[3]=1.0f;
    mat_diffuse[0]=1.0,mat_diffuse[1]=0.0,mat_diffuse[2]=0,mat_diffuse[3]=1.0f;
    mat_specular[0]=1.0,mat_specular[1]=0.0,mat_specular[2]=0,mat_specular[3]=1.0f;
    //const GLfloat high_shininess[] = { 100.0f };

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    //glColor3d(0,1,0);
    glVertex3f(9,5,3);
    glVertex3f(9,5,0);
    glVertex3f(9,10,0);
    glVertex3f(9,10,3);

    // glColor3d(1,.5,0);
    glVertex3f(5,5,0);
    glVertex3f(5,7,0);
    glVertex3f(9,10,0);
    glVertex3f(9,5,0);

    // glColor3d(0,1,1);
    glVertex3f(5,5,0);
    glVertex3f(5,5,3);
    glVertex3f(5,7,3);
    glVertex3f(5,7,0);

    // glColor3d(1,0.5,0.2);
    glVertex3f(5,5,0);
    glVertex3f(9,5,0);
    glVertex3f(9,5,3);
    glVertex3f(5,5,3);

    glEnd();

/////////second er first plane////////
    glBegin(GL_QUADS);
    //glColor3d(1,0.5,1);
    glVertex3f(6.33,8,0);
    glVertex3f(5,7,0);
    glVertex3f(5,7,3);
    glVertex3f(6.33,8,3);

    glEnd();
////////////////second er second plane////////
    glBegin(GL_QUADS);
    //glColor3d(1,.8,.6);
    glVertex3f(7.66,9,0);
    glVertex3f(6.33,8,0);
    glVertex3f(6.33,8,3);
    glVertex3f(7.66,9,3);

    glEnd();
///////////
    glBegin(GL_QUADS);
    // glColor3d(0.1,0.6,0.6);
    glVertex3f(12,11,0);
    glVertex3f(9,10,0);
    glVertex3f(9,10,3);
    glVertex3f(12,11,3);

    glEnd();

    cube();
    cube2();




    mat_ambient[0]=.4,mat_ambient[1]=.4,mat_ambient[2]=.4,mat_ambient[3]=1.0f;
    mat_diffuse[0]=11.5,mat_diffuse[1]=10.5,mat_diffuse[2]=11.0,mat_diffuse[3]=1.0f;
    mat_specular[0]=.5,mat_specular[1]=0.5,mat_specular[2]=1.0,mat_specular[3]=1.0f;
    //const GLfloat high_shininess[] = { 100.0f };

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
/////////////////darano pa//////////////////
    glBegin(GL_QUADS);

    //glColor3d(.5,.5,.5);
    glVertex3f(7,5,3);
    glVertex3f(7,3.5,3);
    glVertex3f(10,3.5,3);
    glVertex3f(10,5,3);
    glEnd();

    glBegin(GL_QUADS);
    // glColor3d(.5,.5,.5);
    glVertex3f(7,5,0);
    glVertex3f(10,5,0);
    glVertex3f(10,3.5,0);
    glVertex3f(7,3.5,0);
    glEnd();
//////////pa////////////////
    glBegin(GL_QUADS);
    // glColor3d(.8,.8,.8);
    glVertex3f(6,3.5,2.5);
    glVertex3f(6,3.5,3.5);
    glVertex3f(11,3.5,3.5);
    glVertex3f(11,3.5,2.5);
    glEnd();


    glBegin(GL_QUADS);
    // glColor3d(.8,.8,.8);
    glVertex3f(6,3.5,-.5);
    glVertex3f(6,3.5,.5);
    glVertex3f(11,3.5,.5);
    glVertex3f(11,3.5,-.5);
    glEnd();
//////////////////pakha//////////////////






    glPushMatrix();
    glTranslated(20*.66,12*.9,-3.5);
    glRotated(90,1,0,0);
    glScaled(.5,.5,.5);
    pakha();
    glPopMatrix();



    pakha();

}


void pakha()
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = 10*t*95;



    GLfloat mat_ambient[]    = { .21f, .21f, .21f, 1.0f };
    GLfloat mat_diffuse[]    = { 0.0f, 1.0f, 0.0f, 1.0f };
    GLfloat mat_specular[]   = { 1.0f, .0f, 0.5f, 1.0f };
    GLfloat high_shininess[] = { 100.0f };

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glPushMatrix();
    glTranslated(10.5,13,1.5);
    glRotated(a,0,1,0);
    glTranslated(-10.5,-13,-1.5);





    glBegin(GL_QUADS);

    glVertex3f(7.5,13,1);
    glVertex3f(7.5,13,2);
    glVertex3f(13.5,13,2);
    glVertex3f(13.5,13,1);
    glEnd();

    glBegin(GL_QUADS);

    glVertex3f(10,13,-1.5);
    glVertex3f(10,13,4.5);
    glVertex3f(11,13,4.5);
    glVertex3f(11,13,-1.5);
    glEnd();





    glRotated(90,1,0,0);
    drawLeftCircle(7.5,1.5);

    righthalfcircle(13.5,1.5);

    glRotated(90,0,0,1);
    drawLeftCircle(-1.5,-10.5);

    righthalfcircle(4.5,-10.5);


    init();

    glPopMatrix();

}





void cube ()
{


    glBegin(GL_QUADS);


    glVertex3f(12,8.3,1);
    glVertex3f(12,7.3,1);
    glVertex3f(12,7.3,2);
    glVertex3f(12,8.3,2);


    glVertex3f(12,8.3,2);
    glVertex3f(12,7.3,2);
    glVertex3f(17,7.3,2);
    glVertex3f(17,8.3,2);


    glVertex3f(17,8.3,1);
    glVertex3f(17,8.3,2);
    glVertex3f(17,7.3,2);
    glVertex3f(17,7.3,1);

    glVertex3f(12,8.3,1);
    glVertex3f(12,8.3,2);
    glVertex3f(17,8.3,2);
    glVertex3f(17,8.3,1);

    glVertex3f(12,7.3,1);
    glVertex3f(17,7.3,1);
    glVertex3f(17,7.3,2);
    glVertex3f(12,7.3,2);


    glVertex3f(12,8.3,1);
    glVertex3f(17,8.3,1);
    glVertex3f(17,7.3,1);
    glVertex3f(12,7.300,1);


    glEnd();
}







void cube2 ()
{


    glBegin(GL_QUADS);

    glVertex3f(17,8.3,1);
    glVertex3f(17,7.3,1);
    glVertex3f(17,7.3,2);
    glVertex3f(17,8.3,2);


    glVertex3f(17,8.3,2);
    glVertex3f(17,7.3,2);
    glVertex3f(19,10.3,2);
    glVertex3f(19,11.3,2);


    glVertex3f(19,11.3,1);
    glVertex3f(19,11.3,2);
    glVertex3f(19,10.3,2);
    glVertex3f(19,10.3,1);

    glVertex3f(17,8.3,1);
    glVertex3f(17,8.3,2);
    glVertex3f(19,11.3,2);
    glVertex3f(19,11.3,1);


    glVertex3f(17,7.3,1);
    glVertex3f(19,10.3,1);
    glVertex3f(19,10.3,2);
    glVertex3f(17,7.3,2);


    glVertex3f(17,8.3,1);
    glVertex3f(19,11.3,1);
    glVertex3f(19,10.3,1);
    glVertex3f(17,7.300,1);


    glEnd();
}

void ccube(double r, double g, double b)
{
    glBegin(GL_QUADS);

    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(-1, 1, 1);

    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);


    glVertex3f(-1, 1, -1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);

    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(-1, -1, -1);


    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);

    glVertex3f(-1, -1, 1);
    glVertex3f(-1, -1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);
    glEnd();
}
//jacck design
void design()
{

    glPushMatrix(); //design
    glScaled(.1,.5,.1);

    glutSolidSphere(2,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,1,0);
    glScaled(.1,.1,.1);

    glutSolidSphere(2,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,-1,0);
    glScaled(.1,.1,.1);
    glutSolidSphere(2,10,10);
    glPopMatrix();






}

int Depth=1;

void drawkoch(GLfloat x,GLfloat y, GLfloat len, GLint iter)
{

    if (iter == -1)
    {
        return;
    }
    else
    {

        iter--;

        drawkoch(x,y, len/3.0, iter);
        drawkoch(x+len/3.0,y, len/3.0, iter);
        drawkoch(x+2.0*len/3.0,y, len/3.0, iter);

        drawkoch(x,y+len/3.0, len/3.0, iter);

        drawkoch(x+2.0*len/3.0,y+len/3.0, len/3.0, iter);

        drawkoch(x,y+2.0*len/3.0, len/3.0, iter);
        drawkoch(x+len/3.0,y+2.0*len/3.0, len/3.0, iter);
        drawkoch(x+2.0*len/3.0,y+2.0*len/3.0, len/3.0, iter);

        glBegin(GL_QUADS);
        glVertex2f(x+len/3.0, y+2.0*len/3.0);
        glVertex2f(x+len/3.0, y+len/3.0);
        glVertex2f(x+2.0*len/3.0, y+len/3.0);
        glVertex2f(x+2.0*len/3.0, y+2.0*len/3.0);
        glEnd();


    }
}

void KochCurve(int depth)
{
    glClear(GL_COLOR_BUFFER_BIT);
    GLfloat mat_ambient[]    = { .3f, .3f, .3f, 1.0f };
    GLfloat mat_diffuse[]    = { 1.0f, 1.0f, 1.f, 1.0f };
    GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat high_shininess[] = { 100.0f };
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glPopMatrix();

    drawkoch(0,0,12, depth);

    glFlush();
}

void envi()
{
    GLfloat mat_ambient[]    = { .3f, .3f, .3f, 1.0f };
    GLfloat mat_diffuse[]    = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat high_shininess[] = { 100.0f };
    if(check==0)
    {
        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
        glPopMatrix();
    }
    else if(check==1)
    {
        glPushMatrix();
        mat_ambient[0]=.3,mat_ambient[1]=.3,mat_ambient[2]=.3,mat_ambient[3]=1.0f;
        mat_diffuse[0]=0.8,mat_diffuse[1]=0.7,mat_diffuse[2]=.6,mat_diffuse[3]=1.0f;
        mat_specular[0]=0.0,mat_specular[1]=0.0,mat_specular[2]=0.0,mat_specular[3]=1.0f;

        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
        glPopMatrix();
    }



    if(check==0)
    {
        ///frame
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D,6);
        glEnable(GL_TEXTURE_2D);

        glTranslated(0,3,1);
        //glRotated(80,0,1,0);
        glScaled(3,2.5,.4);
        ccube(.5,0,.5);
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();

    }



    if(check==0)
    {
        glBindTexture(GL_TEXTURE_2D,3);
        glEnable(GL_TEXTURE_2D);
    }

    ///front wall
    glPushMatrix();
    glTranslated(0,2,0);
    glRotated(-10,0,1,0);
    glScaled(7,7,.4);
    ccube(.5,0,0);
    glPopMatrix();

//glDisable(GL_TEXTURE_2D);
    if(check==1)
    {
        mat_ambient[0]=.3,mat_ambient[1]=.3,mat_ambient[2]=.3,mat_ambient[3]=1.0f;
        mat_diffuse[0]=0.3,mat_diffuse[1]=0.7,mat_diffuse[2]=.6,mat_diffuse[3]=1.0f;
        mat_specular[0]=0.0,mat_specular[1]=0.0,mat_specular[2]=0.0,mat_specular[3]=1.0f;

        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    }
///Left Wall

    glPushMatrix();   //left wall
    glTranslated(-7.6,2,5.5);
    glRotated(80,0,1,0);
    glScaled(7,7,.4);
    ccube(.5,0,.5);
    glPopMatrix();












    mat_ambient[0]=.3,mat_ambient[1]=.3,mat_ambient[2]=.3,mat_ambient[3]=1.0f;
    mat_diffuse[0]=.1,mat_diffuse[1]=0.5,mat_diffuse[2]=1.0,mat_diffuse[3]=1.0f;
    mat_specular[0]=.50,mat_specular[1]=0.2,mat_specular[2]=1.2,mat_specular[3]=1.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);




    if(check==1)
    {

        mat_ambient[0]=.3,mat_ambient[1]=.3,mat_ambient[2]=.3,mat_ambient[3]=1.0f;
        mat_diffuse[0]=.6,mat_diffuse[1]=.8,mat_diffuse[2]=1,mat_diffuse[3]=1.0f;
        mat_specular[0]=.50,mat_specular[1]=0.2,mat_specular[2]=1.2,mat_specular[3]=1.0f;

        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
        glDisable(GL_TEXTURE_2D);
    }

///FLOOR

    if(check==0)

    {


        mat_ambient[0]=.3,mat_ambient[1]=.3,mat_ambient[2]=.3,mat_ambient[3]=1.0f;
        mat_diffuse[0]=1,mat_diffuse[1]=1,mat_diffuse[2]=1,mat_diffuse[3]=1.0f;
        mat_specular[0]=.50,mat_specular[1]=0.2,mat_specular[2]=1.2,mat_specular[3]=1.0f;

        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
        glDisable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D,5);
        glEnable(GL_TEXTURE_2D);



    }

    glPushMatrix();   // floor
    glTranslated(-1,-5,5.5);
    glRotated(-10,0,1,0);
    glScaled(10,.2,10);
    ccube(.1,.5,.5);
    glPopMatrix();





    mat_ambient[0]=.3,mat_ambient[1]=.3,mat_ambient[2]=.3,mat_ambient[3]=1.0f;
    mat_diffuse[0]=.7,mat_diffuse[1]=0.7,mat_diffuse[2]=.7,mat_diffuse[3]=1.0f;
    mat_specular[0]=0.6,mat_specular[1]=.30,mat_specular[2]=.30,mat_specular[3]=1.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glDisable(GL_TEXTURE_2D);
///Table up

    if(check==0)
    {
        glBindTexture(GL_TEXTURE_2D,4);
        glEnable(GL_TEXTURE_2D);
    }
    glPushMatrix();
    glTranslated(-.5,-2.1,6.5);
    glRotated(-10,0,1,0);
    glScaled(4,.2,4);
    ccube(.1,.5,.5);
    glPopMatrix();


    mat_ambient[0]=.3,mat_ambient[1]=.3,mat_ambient[2]=.3,mat_ambient[3]=1.0f;
    mat_diffuse[0]=0.8,mat_diffuse[1]=.6,mat_diffuse[2]=0.5,mat_diffuse[3]=1.0f;
    mat_specular[0]=0.50,mat_specular[1]=.8,mat_specular[2]=.40,mat_specular[3]=1.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    ///Leg 1

    glPushMatrix(); //leg1
    glTranslated(1,-3.5,8.6);
    glRotated(-18,0,1,0);
    glScaled(.3,1.5,2);
    ccube(0,.1,.5);
    glPopMatrix();

    //LEG 2

    glPushMatrix(); //leg2
    glTranslated(-2.5,-3.5,5.6);
    glRotated(-8,0,1,0);
    glScaled(.3,1.5,4);
    ccube(0,.1,.5);
    glPopMatrix();






    mat_ambient[0]=.3,mat_ambient[1]=.3,mat_ambient[2]=.3,mat_ambient[3]=1.0f;
    mat_diffuse[0]=0.7,mat_diffuse[1]=0.0,mat_diffuse[2]=.6,mat_diffuse[3]=1.0f;
    mat_specular[0]=0.0,mat_specular[1]=1.0,mat_specular[2]=.00,mat_specular[3]=1.0f;
    //const GLfloat high_shininess[] = { 100.0f };

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glDisable(GL_TEXTURE_2D);

    glTranslated(-2,0,0);
    ///DESIGN
    glPushMatrix();
    glTranslated(0,-1.1,7);
    glRotated(-45,1,0,0);
    design();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,-1.1,7);
    glRotated(15,1,0,0);
    glRotated(-45,0,0,1);
    design();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,-1.1,7);
    glRotated(45,1,0,1);
    design();
    glPopMatrix();


}


static void resize(int width, int height)
{
    winW=width;
    winH=height;
    const float ar = ((float) width/2.0) / (float) height;
    //const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static GLdouble camTheta = 0;

void cameraRotate()
{
    GLdouble angleInRadians = camTheta * PI / 180.0;
    GLdouble cosangle = cos(angleInRadians);
    GLdouble sinangle = sin(angleInRadians);

    eyez = camRadius * cosangle;
    eyex = camRadius * sinangle;
}
static GLdouble camRoll = 90;
GLdouble rollInRadians = camRoll * PI / 180.0;


static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLightfv(GL_LIGHT2,GL_DIFFUSE,light_ambient_3);


    glScaled(.43,.4,.4);

    glPushMatrix();//for viewport
    glViewport(0, 0, winW/2, winH);
    glTranslated(tx, ty, tz);
    glRotated(a1,0,1,0);
    glRotated(a2,1,0,0);
    glRotated(aa3,0,0,1);
    ownscaled(zoom, zoom, zoom);
    glScaled(1,1,.90);


    glPushMatrix();


    ///koch
    glPushMatrix();
    glTranslated(-7,-5,1);
    glRotated(10,1,0,0);
    glRotated(70,0,1,0);
    glScaled(.75,1,.4);
    KochCurve(Depth);
    glPopMatrix();

    glTranslated(2,0,-10);
    glRotated(-10,0,1,0);
    glRotated(10,1,0,0);
    glScaled(1,1,.8);
    check=0;
    envi();
    glPopMatrix();

    glPushMatrix();

    glTranslated(3.5, -2.3, -4);
    glTranslated(-1,-.5,-7);
    glTranslated(-9*.25,-5*.15,7);
    glRotated(15,1,0,0);




    glScaled(.30,.20,.10);
    helicopter();

    glPopMatrix();

    glPopMatrix();//first vp ends





    glPushMatrix();//2nd vp

    glViewport(winW/2, 0, winW/2, winH);


    glPushMatrix();
    glTranslated(tx, ty, tz);
    // glRotated(20,0,1,0);
    glRotated(a1,0,1,0);
    glRotated(a2,1,0,0);
    glRotated(aa3,0,0,1);
    ownscaled(zoom, zoom, zoom);
    glScaled(1,1,.90);
    glPushMatrix();


    glTranslated(2,0,-10);
    glRotated(10,1,0,0);
    glScaled(1,1,.8);
    check=1;
    envi();
    glPopMatrix();

    glPushMatrix();

    glTranslated(3.5, -2.3, -4);
    glTranslated(-1,-.5,-7);
    glTranslated(-9*.25,-5*.15,7);
    glRotated(15,1,0,0);




    glScaled(.30,.20,.10);
    helicopter();

    glPopMatrix();

    glPopMatrix();
    glPopMatrix();




    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyex,eyey,eyez,cdx,cdy,cdz,hdx,hdy,hdz);


    glutSwapBuffers();
}
int tmp1,tmp2,tmp3;
int ck=0,l_dis=1,l_dis_2=1;

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q':
        a1 += 2.5;
        break;
    case 'Q':
        a1 -= 2.5;
        break;

    case  'w':
        a2 += 2.5;
        break;
    case  'W':
        a2 -= 2.5;
        break;

    case 'e':
        aa3 += 2.5;
        break;
    case 'E':
        aa3 -= 2.5;
        break;
    case 'r':
        if(zoom >= 1.5) break;
        zoom += .15;
        break;
    case 'R':
        if(zoom <= .4) break;
        zoom -= .15;
        break;
    case 't':
        tx++;
        break;
    case 'y':
        ty++;
        break;
    case 'u':
        tz++;
        break;
    case 'T':
        tx--;
        break;
    case 'Y':
        ty--;
        break;
    case 'U':
        tz--;
        break;





    case 'A':
        eyex-=.1;
        break;
    case 'a':
        eyex+=.1;
        break;
    case 'S':
        eyey-=.1;
        break;
    case 's':
        eyey+=.1;
        break;

    case 'D':
        eyez-=.1;
        break;
    case 'd':
        eyez+=.1;
        break;

    case 'F':
        cdx-=.1;
        break;
    case 'f':
        cdx+=.1;
        break;

    case 'G':
        cdy-=.1;
        break;
    case 'g':
        cdy+=.1;
        break;

    case 'H':
        cdz-=1;
        break;
    case 'h':
        cdz+=1;
        break;

    case 'J':
        hdx-=1;
        break;
    case 'j':
        hdx+=1;
        break;

    case 'K':
        hdy-=1;
        break;
    case 'k':
        hdy+=1;
        break;

    case 'L':
        hdz-=1;
        break;

    case 'l':
        hdz+=1;
        break;

    case '7':
        Depth-=1;
        break;

    case '8':
        Depth+=1;
        break;


    case '9':
        if(l_dis)
        {
            glDisable(GL_LIGHT0);
            l_dis=0;
        }
        else
        {
            glEnable(GL_LIGHT0);
            l_dis=1;
        }
        break;
    case '0':
        if(l_dis_2)
        {
            glEnable(GL_LIGHT1);
            l_dis_2=0;
        }
        else
        {
            glDisable(GL_LIGHT1);
            l_dis_2=1;
        }
        break;
//rotate
    case 'm':
        cameraRotate();
        camTheta+=2;
        break;

//rolling
    case 'z':

        angle-=.1;
        hdx=0*cos(angle)-5*sin(angle);
        hdy=0*sin(angle)+5*cos(angle);
        break;


    case 'Z':
        angle+=.1;
        hdx=0*cos(angle)-5*sin(angle);
        hdy=0*sin(angle)+5*cos(angle);
        break;
    //yaw
    case 'x':
        angle-=.1;
        cdy=0*cos(angle)-2*sin(angle);
        cdz=0*sin(angle)+2*cos(angle);

        break;

    case 'X':
        angle+=.1;
        cdy=0*cos(angle)-2*sin(angle);
        cdz=0*sin(angle)+2*cos(angle);

        break;

    //pitch
    case 'c':
        angle-=.1;
        cdx=cos(angle)+sin(angle);
        cdz=-sin(angle)+cos(angle);
        break;
    case 'C':
        angle+=.1;
        cdx=cos(angle)+sin(angle);
        cdz=-sin(angle)+cos(angle);
        break;


    case '+':
        eyex+=(cdx-eyex)/20;
        eyey+=(cdy-eyey)/20;
        eyez+=(cdz-eyez)/20;
        break;
    case '-':
        eyex-=(cdx-eyex)/20;
        eyey-=(cdy-eyey)/20;
        eyez-=(cdz-eyez)/20;
        break;
    }

    glutPostRedisplay();
}

void for_tex()
{

    if(check==0)
    {
        pix[2].readBMPFile("C:\\Users\\User\\Desktop\\New folder\\lab2aman\\ff.bmp");
        pix[2].setTexture(3);
        pix[3].readBMPFile("C:\\Users\\User\\Desktop\\New folder\\lab2aman\\wood.bmp");
        pix[3].setTexture(4);
        pix[4].readBMPFile("C:\\Users\\User\\Desktop\\New folder\\lab2aman\\t.bmp");
        pix[4].setTexture(5);
        pix[5].readBMPFile("C:\\Users\\User\\Desktop\\New folder\\lab2aman\\frame.bmp");
        pix[5].setTexture(6);

    }
}


static void idle(void)
{
    glutPostRedisplay();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000,680);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    for_tex();

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);



    //spot


    glLightfv(GL_LIGHT1,GL_AMBIENT,light_ambient);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,light_diffuse);
    glLightfv(GL_LIGHT1,GL_SPECULAR,light_specular);
    glLightfv(GL_LIGHT1,GL_POSITION,light_position_spot);

    glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,20.0);
    glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,spot_direction);
    glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,2);


    glBegin(GL_LINES);
    glColor3f(1.0f,0.0,0.0);

    glEnd();

    glEnable(GL_LIGHT2);



    glutMainLoop();






    glutMainLoop();

    return EXIT_SUCCESS;
}
