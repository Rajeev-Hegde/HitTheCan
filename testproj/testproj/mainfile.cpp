
#include <stdlib.h> 	
#include <glut.h>
#include<glu.h>
#include <math.h>


float rotate_angle=0,arr_rotation=0;
int step=400,shoot=0,rotate_arrow=0,can6_res=1,can4_res=1,can5_res=1,can1_res=1,no_turns=5,turn_over=1;
float ypos=25;
int ok=1;
float lx=0.0f,lz=-1.0f,py = -100.0f,ly=0.0,yy=-4.0;
float x=0.0f,z=5.0f,decrement=0.0;
float can6_xpos=0.0,can6_ypos=0.0;
int boundary_condition=1,hit_condition=1,can1_hit=1,can4_hit=1,can5_hit=1,can6_hit=1;
float anglex = 0.0f,angley = 0.0f,arrow_z=0;
GLfloat vertices[8][3]={{-350.0,-550.0+step,10},{-350.0,550.0-step,10},
							{350.0,550.0-step,10},{350.0,-550.0+step,10},
							{-350.0,-550.0+step,-900.0},{-350.0,550.0-step,-900.0},
							{350.0,550.0-step,-900.0},{350.0,-550.0+step,-900.0}	
							};

GLUquadricObj *obj = gluNewQuadric();
void draw_tin(int);
void draw_room();
void quad(int ,int ,int ,int );
void draw_center_figure();

void my_menu(int id)
{
	switch(id)
	{
	case 1: rotate_angle=0,arr_rotation=0;
			step=400,shoot=0,rotate_arrow=0,can6_res=1,can4_res=1,can5_res=1,can1_res=1,no_turns=5,turn_over=1;
			ypos=25;
			ok=1;
		    lx=0.0f,lz=-1.0f,py = -100.0f,ly=0.0,yy=-4.0;
            x=0.0f,z=5.0f,decrement=0.0;
            can6_xpos=0.0,can6_ypos=0.0;
            boundary_condition=1,hit_condition=1,can1_hit=1,can4_hit=1,can5_hit=1,can6_hit=1;
            anglex = 0.0f,angley = 0.0f,arrow_z=0;
		break;	
	case 2:exit(0);
		break;
	
	}
	glutPostRedisplay();

}

void side_pole(int var)
{
	glPushMatrix();
		if(var==0)  //left
			glTranslatef(-223.0,0.0,-530);
		else   //right
			glTranslatef(223.0,0.0,-530);
		glRotatef(-90,1.0,0.0,0.0);
		glPushMatrix();
		glRotatef(sin(rotate_angle)*30,0.0,0.0,1.0);
		glPushMatrix();
		glScalef(1.2,1.2,1.2);
		glTranslatef(0.0,2.0,-10.0);
		glRotatef(30,1.0,0.0,0.0);
		
		draw_tin(0);
		
		glPopMatrix();
		
		glDisable(GL_LIGHTING);
		glColor3f(0.0,0.0,0.0);
		gluCylinder(obj,0.40,0.40,40,50,50);
		glPopMatrix();
		if(var==0)
		{
		glTranslatef(3.0,0.0,40.0);
		glRotatef(-90,0.0,1.0,0.0);
		}
		else
		{
			glTranslatef(-3.0,0.0,40.0);
		glRotatef(90,0.0,1.0,0.0);
		}

		gluCylinder(obj,2.0,2.0,130,50,50);
		glEnable(GL_LIGHTING);
	glPopMatrix();
}

void drawpoles()
{
	glDisable(GL_LIGHTING);
	glColor3f(0.0,0.0,0.0);
			glPushMatrix();
			glScalef(1.2,1.2,1.2);
				glPushMatrix();
				glRotatef(100,1.0,0.0,0.0);
				//gluCylinder(obj,0.7,0.7,70.0,30,30);
				glScalef(1.15,1.2,1.0);
				//near black color disc
				glColor3f(0.2,0.2,0.2);
				gluDisk(obj,0.0,10.0,50,50);
				///gray color disc
				glColor3f(0.8,0.8,0.8);
				gluDisk(obj,10.0,20.0,50,50);
				//grape color disc
				glColor3f(0.5,0.2,0.5);
				gluDisk(obj,20.0,24.0,50,50);
				glColor3f(0.0,0.0,0.0);
				glutSolidTorus(1,25,50,50);
				glPopMatrix();



				//left legs with can on top
				glTranslatef(-29.5,0.0,0.0);
					
				glPushMatrix();
					glRotatef(150,1.0,0.0,0.0);
					gluCylinder(obj,0.8,0.8,123.0,50,50);
				glPopMatrix();
				glPushMatrix();
					glRotatef(-200,0.0,-1.0,1.0);
					gluCylinder(obj,0.7,0.7,63.0,50,50);
				glPopMatrix();


				//right legs
				glTranslatef(59.0,0.0,0.0);
					
				glPushMatrix();
					glRotatef(150,1.0,0.0,0.0);
					gluCylinder(obj,0.7,0.7,123.0,50,50);
				glPopMatrix();
				glPushMatrix();
					glRotatef(195,0.0,-1.0,1.0);
					gluCylinder(obj,0.7,0.7,63.0,50,50);
				glPopMatrix();
			glPopMatrix();
			glEnable(GL_LIGHTING);
}

void arrow(int check)
{
	
	glEnable(GL_NORMALIZE);
	glColor3f(.5,0.0,.5);
	if(check)
	{
	glTranslatef(0.0,-20.0,5-arrow_z);
	glRotatef(-165-decrement,1.0,0.0,0.0);
	}
	else
	{
		glTranslatef(0.0,-20.0,5);
		glRotatef(-180,1.0,0.0,0.0);
	
	}
	if(check)
	if(rotate_arrow)
	glRotatef(arr_rotation*140,0.0,0.0,1.0);
	glPushMatrix();
	glDisable(GL_LIGHTING);
	gluDisk(obj,0.0,.6,30,30);
	glEnable(GL_LIGHTING);
	glRotatef(45,0.0,0.0,1.0);
	glScalef(1.0,.2,1.0);
	glutSolidCone(2.0,4.0,4,10);
	glPopMatrix();
	glPushMatrix();
	glColor3f(.5,0.5,0.0);
	glRotatef(-45,0.0,0.0,1.0);
	glScalef(1.0,.2,1.0);
	glutSolidCone(2.0,4.0,4,10);
	glPopMatrix();
	glColor3f(.5,0.5,.5);
	glTranslatef(0.0,0.0,2.0);
	gluCylinder(obj,0.3,0.3,30,30,30);
	glTranslatef(0.0,0.0,30);
	glDisable(GL_LIGHTING);
	gluDisk(obj,0.0,.9,30,30);
	glEnable(GL_LIGHTING);
	glutSolidCone(2.0,3.0,3,10);
	

}

void display (void) {
	//hjsantoshb11@gmail.com
	
    glClearColor (1.0,1.0,1.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
	glEnable(GLU_SMOOTH);
	
	//show number of chances
	if(!shoot)
	for(int chance=0;chance<no_turns;chance++)
	{	
	glPushMatrix();
	glTranslatef(0.5+0.07*chance,-0.4,-1);
	glScalef(.007,.007,.007);
	glRotatef(70,1.0,0.0,0.0);
	arrow(0);
	glPopMatrix();
	}
	//center arrow
	glPushMatrix();
			arrow(1);
		glPopMatrix();
    gluLookAt(x, py,z,x+lx,py+ly, z+lz,0.0, 1.0, 0.0);
	
	//draw the room
	draw_room();
	
	if(can4_res)
	side_pole(0);
	
	if(can5_res)
	side_pole(1);
	//draw the center figure
	glPushMatrix();
	draw_center_figure();
	glPopMatrix();
	
	
	glutSwapBuffers();

}




void draw_room()
{
	//glScalef(2.2,1.5,4.5);
	//glutWireCube(35);
	glDisable(GL_LIGHTING);
	////draw cube////
	glPushMatrix();
	//glTranslatef(0.0,0.0,-50.0);
	//glScalef(10.0,10.0,100.0);
	glColor3f(1,0,0);
	quad(0,3,2,1);
	glColor3f(.5,.3,.3);
	quad(2,3,7,6);
	glColor3f(0.4,0.4,0.4);
	quad(0,4,7,3);
	glColor3f(.4,.4,.4);
	quad(1,2,6,5);
	glColor3f(.4,.3,.3);
	quad(4,5,6,7);
	glColor3f(.5,.3,.3);
	quad(0,1,5,4);
	glPopMatrix();
	glEnable(GL_LIGHTING);
	}

void quad(int a,int b,int c,int d)
{
	glBegin(GL_QUADS);
			
			glVertex3fv(vertices[a]);
			glVertex3fv(vertices[b]);
			glVertex3fv(vertices[c]);
			glVertex3fv(vertices[d]);
	glEnd();

}

void draw_center_figure()
{
	
	

	glTranslatef(0,-77.0,-720.0);
	// draw the poles
	drawpoles();
	
	glPushMatrix();
	//glTranslatef(0.0,1.2,0.0);
	glRotatef(-77,1.0,0.0,0.0);
	if(can1_res)
	draw_tin(0);
	glPopMatrix();
	
	if(can6_res)
	{
	//draw tin with rope present
		glScalef(1.4,1.4,1.4);
		glRotatef(sin(rotate_angle)*40,0.0,0.0,0.7);

		glTranslatef(0.0,-47.4,-10.0);
		//glTranslatef(-1.0,-1.0,-10.0);
		glRotatef(-60,1.0,0.0,0.0);
		draw_tin(1);
	}
}


void draw_tin(int rope_present)
{
	
	
	glColor3f(1,0,0);
	
	glPushMatrix();
			//glTranslatef(0.0,2.0,5.0);
			//gluDisk(obj,0.0,3.0,50,50);
			glTranslatef(0.0,0.0,-0.6);
			gluCylinder(obj,3.0, 4.0, 0.6, 60, 30);
			glTranslatef(0.0,0.0,0.08);
			gluCylinder(obj,3.7,3.7,.5,50,50);
			glTranslatef(0.0,0.0,-0.05);
			glDisable(GL_LIGHTING);
			glColor3f(.4,.4,.4);
			gluDisk(obj,0.0,3.7,50,50);
			glEnable(GL_LIGHTING);
			//gluCylinder(obj,
			//glutSolidTorus(1.0,3.0,14.0,50);
	glPopMatrix();

	glColor3f(0.0,1.0,0.0);
	//glRotatef(-25,1.0,0.0,0.0);
	gluDisk(obj,0.0,4.0,50,50);
	gluCylinder(obj, 4, 4, 10, 60, 30);
	glPushMatrix();
			glTranslatef(0.0,0.0,10);
	
			glPushMatrix();
				gluDisk(obj,0.0,4.0,50,50);
				gluCylinder(obj,3.7,3.6,0.6,30,30);
				glTranslatef(0.0,0.0,.6);
				gluDisk(obj,0.0,3.6,30,30);
			glPopMatrix();

			if(rope_present)
			{
			////this is for the rope to surround the tin 
			glPushMatrix();
				glTranslatef(0.0,0.0,.5);
				glDisable(GL_LIGHTING);
				glColor3f(0.0,0.0,0.0);
				gluPartialDisk(obj,4.0,4.15,30,30,90,180);
				glScalef(1.03,1.12,1.0);
				//gluDisk(obj,3.9,4.1,30,30);
				gluPartialDisk(obj,3.85,4.05,30,30,270,180);
			
				glTranslatef(0.0,4.1,0.0);
				glRotatef(-30,1.0,0.0,0.0);
				gluCylinder(obj,0.2,0.2,36,30,30);

		
				glEnable(GL_LIGHTING);
			glPopMatrix();
			}

			gluCylinder(obj, 4.0, 3.8,.2, 30, 30);
			glTranslatef(0.0,0.0,0.2);
			gluCylinder(obj, 3.8, 3.8,.2, 30, 30);
			glTranslatef(0.0,0.0,.2);
			gluCylinder(obj,3.8,4.0,.2,30,30);
			glTranslatef(0.0,0.0,.1);
			gluCylinder(obj,4.0,4.0,.3,30,30);
			//glTranslatef(0.0,0.0,1.5);
			//glRotatef(180,0,0,-25);
			//glutSolidTorus(1.0,3.0,5,50);
			//glutSolidTorus(1.0,3.0,15,50);
	glPopMatrix();

	glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(0.0,0.0,10.7);
			glColor3f(0.0,0.0,0.0);
			glBegin(GL_POLYGON);
				glVertex3f(-1.5,-1.5,0.0);
				glVertex3f(1.5,-1.5,0.0);
				//glVertex3f(3.0,1.5,0.0);
				glVertex3f(1.1,1.8,0.0);
				glVertex3f(-1.1,1.8,0.0);
			glEnd();
			glPushMatrix();
				glTranslatef(0.0,-1.5,0.0);
				glPushMatrix();
					glEnable(GL_LIGHTING);
					gluCylinder(obj,0.7,0.7,0.3,30,30);
					gluCylinder(obj,0.9,0.9,.3,30,30);
					glTranslatef(0.0,0.0,0.3);
					gluDisk(obj,0.7,0.9,30,30);
					glDisable(GL_LIGHTING);
				glPopMatrix();
				gluPartialDisk(obj,0.0,1.5,30,30,90,180);
			glPopMatrix();
	
			glPushMatrix();
				glTranslatef(0.0,1.8,0.0);
				gluPartialDisk(obj,0.0,1.1,30,30,270,180);
			glPopMatrix();

			glEnable(GL_LIGHTING);
	glPopMatrix();
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 1000.0);
    glMatrixMode (GL_MODELVIEW);
}

void lightsOn()
{
	int color=0;


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
       

}


void keyboard (unsigned char key, int kx, int ky)
{
	float fraction = 10.0f;
	switch(key)
	{
		case 'd': 
					if((anglex+0.01)<=1)
					{
                     anglex += 0.01f;
                     lx = sin(anglex);
                     lz = -cos(anglex);
					}
                     break;

		case 'a':	 if((anglex-0.01)>=-1)
					{
					 anglex -= 0.01f;
                     lx = sin(anglex); 
                     lz = -cos(anglex);
					}
                     break;
		case 'y': py+=3; break;
		case 'h': py-=3; break;
		case 's':		if((angley-0.001)>=-0.5)
						{
						angley -= 0.01f;
						ly = sin(angley);
						py+=0.001;
						}
					/*
                     x -= lx * fraction;
                     z -= lz * fraction;
					 */
                     break;

		case 'w':		if((angley+0.001)<=1)
						{
						angley += 0.01f;
						ly = sin(angley);
						py-=0.001;
						}
                     break;
		case 't':	shoot=1;
					rotate_arrow=1;
					break;
		case 'p' :  no_turns--;
					if(no_turns>=0)
					{
					if(can6_hit==0)
						can6_res=0;
					if(can4_hit==0)
						can4_res=0;
					if(can5_hit==0)
						can5_res=0;
					if(can1_hit==0)
						can1_res=0;
					lx=0.0f,lz=-1.0f,py = -100.0f,ly=0.0;
					x=0.0f,z=5.0f,decrement=0.0;
					rotate_angle=0,arr_rotation=0;
					step=400,shoot=0,rotate_arrow=0,turn_over=1;
					anglex = 0.0f,angley = 0.0f,arrow_z=0.0,can6_hit=1;
					}
					break;
	}
	glutPostRedisplay();
}


void idle()
{
	if(turn_over)
	{
	float fraction = 1.0f;
	
	if(!shoot)
	{
		if(can6_hit)
		rotate_angle+=.01;
	}
	else
	{
		if(can6_hit)
		rotate_angle+=0.003;
	}
	if(rotate_angle>=360.0)
	{
		rotate_angle=0.0;	
	}
	if(arr_rotation>=360)
		arr_rotation=0.0;
	
		
	if(shoot)
	{
		
		if(arrow_z<=65)
		{
			arr_rotation+=0.1;
			arrow_z+=4;
			fraction=20.0;
			boundary_condition=((z-lz*fraction)>=-800)&&((x+lx*fraction)<250.0)&&((x+lx*fraction)>=-250.0)&&((py+ly*fraction)<100.0)&&((py+ly*fraction)>=-100.0);
			if(boundary_condition)
						{
							x += lx * fraction;
							py+=ly*fraction;
							//yy=py;
							z += lz * fraction;
						}
						else
							rotate_arrow=0;
		}
		else
		{

			arr_rotation+=0.008;
			boundary_condition=((z-lz*fraction)>=-800)&&((x+lx*fraction)<250.0)&&((x+lx*fraction)>=-250.0)&&((py+ly*fraction)<100.0)&&((py+ly*fraction)>=-110.0);
			hit_condition=!((x<35)&&(x>-35)&&(py<-40)&&(py>-55)&&(z<-630)&&(z>-650));
			can4_hit=!((x<-200)&&(x>-210)&&(py<10)&&(py>0)&&(z<-250)&&(z>-500));
			can5_hit=!((x>205)&&(x<210)&&(py<10)&&(py>0)&&(z<-260)&&(z>-500));
			can6_hit=!((z<-650)&&(z>-670)&&(x<10)&&(x>-10)&&(py>-120)&&(py<-100));
			if(can6_hit&&hit_condition&&boundary_condition&&can4_hit&&can5_hit)
			{
							decrement+=.03;
							angley-=0.0007;
							ly = sin(angley);
							py+=0.0007;


							x += lx * fraction;
							py+=ly*fraction;
							//yy=py;
							z += lz * fraction;
			}
			else
			{
							rotate_arrow=0;
							if(can6_hit==0)
							if(((sin(rotate_angle)>=0.154)||(sin(rotate_angle)<=-0.154)))
							{
									can6_hit=1;
									turn_over=0;
							}
							
							if(hit_condition==0)
							{
								can1_hit=!((x<5)&&(x>-5));
							}
									
							

			}
		}

							
						
	}

					
	glutPostRedisplay();
	}
}

int main () {
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize (1366, 768);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Hit The Can");
    glutDisplayFunc (display);
    glutReshapeFunc (reshape);
    glEnable(GL_DEPTH_TEST);
    glutIdleFunc (idle);
    glutKeyboardFunc (keyboard);
	glutCreateMenu(my_menu);
	glutAddMenuEntry("RESTART",1);
	glutAddMenuEntry("QUIT",2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
    lightsOn();
    glutMainLoop ();
    return 0;
} 


