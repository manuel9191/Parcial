//MANUEL ALBERTO MARTINEZ ROMERO - PARCIAL 1 ALGORITMOS GRAFICOS
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

//variable global para entrar a los if de la funcion figura
int ab = 0;
//funcion que genera la figura
void figuras();

void init(void)
{
	glColor3f(1.0, 0.0, 0.0); //Aplica a las Figuras color rojo
  
}
void reshape(int m, int n)
{
glViewport(0, 0, (GLsizei) m, (GLsizei) n);
// Activamos la matriz de proyeccion.
glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
glLoadIdentity();
// Usamos proyeccion ortogonal
glOrtho(-300, 300, -300, 300, -300, 300);
// Activamos la matriz de modelado/visionado.
glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
glLoadIdentity();
}
void display(void)
{
// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode( GL_MODELVIEW_MATRIX );
glLoadIdentity();

glPushMatrix();
//setMaterial
figuras();
//tipoM();
glFlush();
}

void figuras(){
	if (ab == 1){ //Tecla 1 Figura de una esfera
	//Rotacion de 25 grados en torno al eje x
glRotated(25.0, 1.0, 0.0, 0.0);
//Rotacion de -30 grados en torno al eje y
glRotated(-30.0, 0.0, 1.0, 0.0);
glutWireSphere(150.0, 150.0, 150.0); 

	}
	if(ab == 2){ //Tecla 2 Figura de un cubo
		//Rotacion de 25 grados en torno al eje x
glRotated(25.0, 1.0, 0.0, 0.0);
//Rotacion de -30 grados en torno al eje y
glRotated(-30.0, 0.0, 1.0, 0.0);
glutWireCube(150.0); 
		}
	if(ab == 3){  //Tecla 3 Figura de un cono
			//Rotacion de 25 grados en torno al eje x
glRotated(60.0, 1.0, 0.0, 0.0);
glutWireCone(150.0, 150.0, 150.0, 150.0); 
			}
	if (ab == 4){	//Tecla 4 Figura de un dodecaedro
				
glScalef(150.0, 150.0, 1.0);
glRotated(90.0, 150.0, 150.0, 0.0);
//glRotated(-30.0, 0.0, 0.0, 1.0);
glutWireDodecahedron(); 
				}
	if (ab == 5){  //Tecla 5 Figura de un Octahedro
		
glScalef(150.0, 150.0, 1.0);
glRotated(25.0, 1.0, 1.0, 0.0);
glutWireOctahedron();			
					}
	if (ab == 6){  //Tecla 6 Figura de un tetraedro
		
glScalef(150.0, 150.0, 1.0);
glRotated(90.0, 1.0, 150.0, 0.0);
glutWireTetrahedron();			
					}
	if (ab == 7){   //Tecla 7 Figura de un Icosaedro
		
glScalef(150.0, 150.0, 1.0);
glRotated(90.0, 1.0, 150.0, 0.0);
glutWireIcosahedron();			
					}
	if (ab == 8){  //Tecla 8 Figura de una Tetera	
		
//Rotacion de 25 grados en torno al eje x
glRotated(25.0, 1.0, 0.0, 0.0);
//Rotacion de -30 grados en torno al eje y
glRotated(-30.0, 0.0, 1.0, 0.0);
glutWireTeapot(150); 		
					}
	
	}


void keyboard(unsigned char key, int x, int y){
switch (key){
case '1':
ab = 1;
break;
case '2':	
ab = 2;
break;
case '3' :
ab = 3;
break;
case '4' :
ab = 4;
break;
case '5' :
ab = 5;
break;
case '6' :
ab = 6;
break;
case '7' :
ab = 7;
break;
case '8' :
ab = 8;
break;
case 27:
exit(0);
}
glutPostRedisplay(); // actualizacion de visualizacion
}
int main(int argc, char **argv){
// Inicializo OpenGL
glutInit(&argc, argv);
// Activamos buffer simple y colores del tipo RGB
glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
glutInitWindowSize (800, 600);
// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
glutInitWindowPosition (0, 0);
// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
glutCreateWindow ("Parcial #1 Algoritmos Graficos");
// Inicializamos el sistema
init();
glutDisplayFunc(display);
glutKeyboardFunc(keyboard); //invoca funcion de teclado
glutReshapeFunc(reshape);
glutMainLoop();
return 0;
}
