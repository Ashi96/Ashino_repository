#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926
#define g  9.8			   																		//gravity
#define R2 1.4142135	   																		//root2

static GLfloat t   = 0.0;
static GLfloat dt  = 0.05; 																		//time
static GLfloat ex  = 0.8;  																		//coefficient of restitution_x
static GLfloat ey  = 0.8;  																		//coefficient of restitution_y
static GLint c     = 0.0;  																		//counter

struct ball{
	char   m;
	double x,y,tht;
	double dx,dy;
	double ddx,ddy;
};

struct Leg{
	char   m;
	double len;
	double rps;
	double x,y,tht;
	double dx,dy;
	double ddx,ddy;
};

struct ball b1;            																		//ball
struct Leg leg;			   																		//leg

void display(void)
{  
	glClear(GL_COLOR_BUFFER_BIT);

	if(t==0){																					//initial state
		b1.m = 38;
		b1.x =-50.0; b1.y=-178.0;
		b1.dx = 0.0; b1.dy = 0.0;
		b1.ddx= 0.0; b1.ddy = -g;
		leg.m = 1;
		leg.rps = 20;
		leg.len =250*R2;
	}

	glPushMatrix();																				//ball
	glTranslatef(b1.x,b1.y,0.0);																//ball position
	glBegin(GL_POLYGON);
	glColor3d(1.0f,0.0f,0.0f);
	for(b1.tht=0;b1.tht<=360;b1.tht+=10){
		glVertex2d(22*cos(b1.tht*PI/180.0),22*sin(b1.tht*PI/180.0));
		}
	glEnd();
	glFlush();
	glPopMatrix();
	
	glPushMatrix(); 																			//A wall and ground
	glBegin(GL_LINE_STRIP);
	glColor3d(0.6f,0.5725490196f,0.2f);
	glVertex2d(-490,-200);
	glVertex2d(990,-200);
	glVertex2d(990,490);
	glEnd();
	glFlush();
	glPopMatrix();

	glPushMatrix();																			    //robot's leg
	glTranslatef(-100.0,150.0,0.0);
	glRotatef(leg.tht,0.0,0.0,1.0);
	glTranslatef(100.0,-150.0,0.0);
	glBegin(GL_POLYGON);
	glColor3d(0.0f,0.0f,0.0f);
	glVertex2d(-100,150);
	glVertex2d(-450,150);
	glVertex2d(-450,100);
	glVertex2d(-400,130);
	glVertex2d(-100,130);
	glEnd();
	glFlush();
	glPopMatrix();

	glutSwapBuffers();
}

void simu(void)
{
	leg.dx = -(leg.len*(-leg.rps*sin(leg.rps*t)));
	leg.dy =   leg.len*(leg.rps*cos(leg.rps*t));
	
	if(90<=c&&c<92){
		b1.x += b1.dx*dt;
		b1.y += b1.dy*dt;
		b1.dx = leg.m * leg.dx/b1.m;
		b1.dy = leg.m * leg.dy/b1.m;
	}else if((b1.x+22<990)&&(b1.y-22>=-200)){
		b1.dx = b1.dx + b1.ddx*dt;
		b1.dy = b1.dy + b1.ddy*dt;
		b1.x += b1.dx*dt;
		b1.y += b1.dy*dt;
	}else if(b1.x+22>990){
		b1.dx = ex * -(b1.dx);
		b1.x += b1.dx*dt;
	}else if(b1.y-22<-200){
		b1.dy = ey * -(b1.dy);
		b1.y += b1.dy*dt;
	}

	t = t+dt;
	c++;
	leg.tht += 1.0;
	
	if(leg.tht>161)
	leg.tht -= 1.0;

	glutPostRedisplay();
}

void init(void)
{
	glClearColor(0.0,0.8,0.8,0.0);
	glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{
	glViewport( 0, 0, w, h );
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500.0, 1000.0, -500.0, 500.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y){
	switch (button) {
		case GLUT_LEFT_BUTTON:
			if ( state == GLUT_DOWN)
				glutIdleFunc(simu);
			break;
		case GLUT_RIGHT_BUTTON:
			if ( state == GLUT_DOWN)
				glutIdleFunc(NULL);
			break;
		default:
			break;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	if ( key == '\x1b') exit(0);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (800, 500);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

