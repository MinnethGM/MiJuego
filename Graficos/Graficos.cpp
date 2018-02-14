// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include <iostream>
using namespace std;


//Declaracion de ventana 
GLFWwindow *window;
GLfloat red, green, blue;
GLfloat ty = -0.8f;
GLfloat tx = 0.0f;
double tiempoAnterior = 0.0;
double velocidad = 0.7;



GLfloat angulo = 0.0f;
GLfloat velocidadAngular = 180.0f;

GLfloat enemigoX = 0.0f;
GLfloat enemigoY = 0.8f;

GLfloat balaX = 0.0f;
GLfloat balaY = 0.0f;
GLboolean disparando;

void checarColisiones()
{
	if (tx >= enemigoX - 0.08 &&
		tx <= enemigoX + 0.08 &&
		ty >= enemigoY - 0.08 &&
		ty <= enemigoY + 0.08)
	{
		exit(0);
	}
}

void actualizar() { 
	//Aqui esta bien para cambiar los valores de las variables de mi programa
	
	/*red += 0.001;
	green += 0.002;
	blue += 0.003;

	if (red > 1) red = 0;
	if (green > 1) green = 0;
	if (blue > 1) blue = 0;
	*/
	double tiempoActual = glfwGetTime();
	double tiempoTranscurrido = tiempoActual - tiempoAnterior;


	
	//DERECHA
	int estadoDerecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoDerecha == GLFW_PRESS)
	{
		if (tx < 1)
			tx += velocidad * tiempoTranscurrido;
		
	}

	//IZQUIERDA
	int estadoIzquierda = glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoIzquierda == GLFW_PRESS)
	{
		if (tx < 1)
			tx -= velocidad * tiempoTranscurrido;

	}
	


	

	int estadoTeclaEspacio = glfwGetKey(window, GLFW_KEY_SPACE);
	if (estadoTeclaEspacio == GLFW_PRESS)
	{
		balaX = tx;
		balaY = ty;
		/*if (disparando == true)
		{
			glScalef(0.8f, 0.8f, 0.8f);
		}*/
	}

	tiempoAnterior = tiempoActual;

}
void dibujarBala()
{
	glPushMatrix();
	glTranslatef(balaX, balaY, 0.0f);
	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	for (float i = 0; i < 360; i++)
	{
		glVertex3f(0.2*cos(i) + 0.4, 0.2*sin(i) + 0.8, 0.0f);

	}

	glEnd();//finaliza rutina
	glPopMatrix();
}

void dibujarHeroe() {
	glPushMatrix();
	glTranslatef(tx, ty, 0.0f);
	//glRotatef(angulo, 0.0f, 0.0f, 1.0f);
	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_TRIANGLES);//Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();
}


void dibujarEnemigo() {

	/////////////////////////////lado///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.5f, 0.0f, 0.3f);


	glVertex3f(-9.5f, 0.5f, 0.0f);
	glVertex3f(-9.5f, -0.5f, 0.0f);
	glVertex3f(-10.5f, -0.5f, 0.0f);
	glVertex3f(-10.5f, 0.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();

	/////////////////////////////////////////INICIAN LOS 0///////////////////////////////////////////////////

	/////////////////////////////0.1///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.5f, 0.0f, 0.3f);
	

	glVertex3f(-7.5f, 0.5f, 0.0f);
	glVertex3f(-7.5f, -0.5f, 0.0f);
	glVertex3f(-8.5f, -0.5f, 0.0f);
	glVertex3f(-8.5f, 0.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();


	/////////////////////////////////////////INICIAN LOS 1///////////////////////////////////////////////////

	/////////////////////////////1.1///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.5f, 0.0f, 0.3f);

	glVertex3f(-5.5f, 0.5f, 0.0f);
	glVertex3f(-5.5f, -0.5f, 0.0f);
	glVertex3f(-6.5f, -0.5f, 0.0f);
	glVertex3f(-6.5f, 0.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();

	/////////////////////////////1.2///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.0f, 0.0f, 1.0f);

	glVertex3f(-5.5f, -1.5f, 0.0f);
	glVertex3f(-5.5f, -2.5f, 0.0f);
	glVertex3f(-6.5f, -2.5f, 0.0f);
	glVertex3f(-6.5f, -1.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();

	/////////////////////////////////////////INICIAN LOS 2///////////////////////////////////////////////////

	/////////////////////////////2.1///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.5f, 0.0f, 0.3f);

	glVertex3f(-3.5f, 0.5f, 0.0f);
	glVertex3f(-3.5f, -0.5f, 0.0f);
	glVertex3f(-4.5f, -0.5f, 0.0f);
	glVertex3f(-4.5f, 0.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();

	/////////////////////////////2.2///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.0f, 0.0f, 1.0f);

	glVertex3f(-3.5f, -1.5f, 0.0f);
	glVertex3f(-3.5f, -2.5f, 0.0f);
	glVertex3f(-4.5f, -2.5f, 0.0f);
	glVertex3f(-4.5f, -1.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();

	/////////////////////////////2.3///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.0f, 0.7f);

	glVertex3f(-3.5f, -3.5f, 0.0f);
	glVertex3f(-3.5f, -4.5f, 0.0f);
	glVertex3f(-4.5f, -4.5f, 0.0f);
	glVertex3f(-4.5f, -3.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();


	/////////////////////////////////////////INICIAN LOS 3///////////////////////////////////////////////////

	/////////////////////////////3.1///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.5f, 0.0f, 0.3f);

	glVertex3f(-1.5f, 0.5f, 0.0f);
	glVertex3f(-1.5f, -0.5f, 0.0f);
	glVertex3f(-2.5f, -0.5f, 0.0f);
	glVertex3f(-2.5f, 0.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();


	/////////////////////////////3.2///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.0f, 0.0f, 1.0f);

	glVertex3f(-1.5f, -1.5f, 0.0f);
	glVertex3f(-1.5f, -2.5f, 0.0f);
	glVertex3f(-2.5f, -2.5f, 0.0f);
	glVertex3f(-2.5f, -1.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();

	
	/////////////////////////////3.3///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.0f, 0.7f);

	glVertex3f(-1.5f, -3.5f, 0.0f);
	glVertex3f(-1.5f, -4.5f, 0.0f);
	glVertex3f(-2.5f, -4.5f, 0.0f);
	glVertex3f(-2.5f, -3.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();


	/////////////////////////////3.4///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.5f, 0.0f, 0.3f);

	glVertex3f(-1.5f, -5.5f, 0.0f);
	glVertex3f(-1.5f, -6.5f, 0.0f);
	glVertex3f(-2.5f, -6.5f, 0.0f);
	glVertex3f(-2.5f, -5.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();

	/////////////////////////////////////////INICIAN LOS 4///////////////////////////////////////////////////

	/////////////////////////////4.1///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);
	
	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.5f, 0.0f, 0.3f);

	glVertex3f(0.5f, 0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();


	/////////////////////////////4.2///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.0f, 0.0f, 1.0f);

	glVertex3f(0.5f, -1.5f, 0.0f);
	glVertex3f(0.5f, -2.5f, 0.0f);
	glVertex3f(-0.5f, -2.5f, 0.0f);
	glVertex3f(-0.5f, -1.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();

	/////////////////////////////4.3///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.0f, 0.7f);

	glVertex3f(0.5f, -3.5f, 0.0f);
	glVertex3f(0.5f, -4.5f, 0.0f);
	glVertex3f(-0.5f, -4.5f, 0.0f);
	glVertex3f(-0.5f, -3.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();

	/////////////////////////////4.4///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.5f, 0.0f, 0.3f);

	glVertex3f(0.5f, -5.5f, 0.0f);
	glVertex3f(0.5f, -6.5f, 0.0f);
	glVertex3f(-0.5f, -6.5f, 0.0f);
	glVertex3f(-0.5f, -5.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();

	/////////////////////////////4.5///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.0f, 0.0f, 1.0f);

	glVertex3f(0.5f, -7.5f, 0.0f);
	glVertex3f(0.5f, -8.5f, 0.0f);
	glVertex3f(-0.5f, -8.5f, 0.0f);
	glVertex3f(-0.5f, -7.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();

	/////////////////////////////////////////INICIAN LOS 5///////////////////////////////////////////////////

	/////////////////////////////5.1///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.5f, 0.0f, 0.3f);

	glVertex3f(1.5f, 0.5f, 0.0f);
	glVertex3f(1.5f, -0.5f, 0.0f);
	glVertex3f(2.5f, -0.5f, 0.0f);
	glVertex3f(2.5f, 0.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();


	/////////////////////////////5.2///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.0f, 0.0f, 1.0f);

	glVertex3f(1.5f, -1.5f, 0.0f);
	glVertex3f(1.5f, -2.5f, 0.0f);
	glVertex3f(2.5f, -2.5f, 0.0f);
	glVertex3f(2.5f, -1.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();


	/////////////////////////////5.3///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.0f, 0.7f);

	glVertex3f(1.5f, -3.5f, 0.0f);
	glVertex3f(1.5f, -4.5f, 0.0f);
	glVertex3f(2.5f, -4.5f, 0.0f);
	glVertex3f(2.5f, -3.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();


	/////////////////////////////5.4///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.5f, 0.0f, 0.3f);

	glVertex3f(1.5f, -5.5f, 0.0f);
	glVertex3f(1.5f, -6.5f, 0.0f);
	glVertex3f(2.5f, -6.5f, 0.0f);
	glVertex3f(2.5f, -5.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();

	/////////////////////////////////////////INICIAN LOS 6///////////////////////////////////////////////////

	/////////////////////////////6.1///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.5f, 0.0f, 0.3f);

	glVertex3f(3.5f, 0.5f, 0.0f);
	glVertex3f(3.5f, -0.5f, 0.0f);
	glVertex3f(4.5f, -0.5f, 0.0f);
	glVertex3f(4.5f, 0.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();

	/////////////////////////////6.2///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.0f, 0.0f, 1.0f);

	glVertex3f(3.5f, -1.5f, 0.0f);
	glVertex3f(3.5f, -2.5f, 0.0f);
	glVertex3f(4.5f, -2.5f, 0.0f);
	glVertex3f(4.5f, -1.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();

	/////////////////////////////6.3///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.0f, 0.7f);

	glVertex3f(3.5f, -3.5f, 0.0f);
	glVertex3f(3.5f, -4.5f, 0.0f);
	glVertex3f(4.5f, -4.5f, 0.0f);
	glVertex3f(4.5f, -3.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();

	/////////////////////////////////////////INICIAN LOS 7///////////////////////////////////////////////////

	/////////////////////////////7.1///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.5f, 0.0f, 0.3f);

	glVertex3f(5.5f, 0.5f, 0.0f);
	glVertex3f(5.5f, -0.5f, 0.0f);
	glVertex3f(6.5f, -0.5f, 0.0f);
	glVertex3f(6.5f, 0.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();

	/////////////////////////////7.2///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.0f, 0.0f, 1.0f);

	glVertex3f(5.5f, -1.5f, 0.0f);
	glVertex3f(5.5f, -2.5f, 0.0f);
	glVertex3f(6.5f, -2.5f, 0.0f);
	glVertex3f(6.5f, -1.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();


	/////////////////////////////////////////INICIAN LOS 8///////////////////////////////////////////////////

	/////////////////////////////8.1///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.5f, 0.0f, 0.3f);

	glVertex3f(7.5f, 0.5f, 0.0f);
	glVertex3f(7.5f, -0.5f, 0.0f);
	glVertex3f(8.5f, -0.5f, 0.0f);
	glVertex3f(8.5f, 0.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();

	/////////////////////////////lado///////////////////////////
	glPushMatrix();
	glTranslatef(enemigoX, enemigoY, 0.0f);

	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_QUADS);//Inicia la rutina con un modo de dibujo

	glColor3f(0.5f, 0.0f, 0.3f);


	glVertex3f(9.5f, 0.5f, 0.0f);
	glVertex3f(9.5f, -0.5f, 0.0f);
	glVertex3f(10.5f, -0.5f, 0.0f);
	glVertex3f(10.5f, 0.5f, 0.0f);


	glEnd();//finaliza rutina
	glPopMatrix();
}


void dibujar() {
	dibujarHeroe();
	dibujarEnemigo();
	dibujarBala();

}
void key_callback(GLFWwindow* window, int key,
	int scancode, int action, int mods)
{
	if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT)) 
	{
		if (ty < 0.9) 
			ty += 0.05;
	}

	if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		if (ty > -0.9)
		ty -= 0.05f;
	}

	if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		if (tx < 0.9)
		tx += 0.05;
	}

	if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		if (tx > -0.9)
		tx -= 0.05f;
	}

	if (key == GLFW_KEY_SPACE && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		dibujarBala();

	}
}

int main()
{
	
	//Propiedades de la ventana
	GLfloat ancho = 1024;
	GLfloat alto = 768;

	//Inicializacion de GLFW
	if (!glfwInit()) {
		//Si no se inicio bien, terminar la ejecucion
		exit(EXIT_FAILURE);
	}

	//Inicializar la ventana
	window = glfwCreateWindow(ancho, alto, "Graficos", NULL, NULL);
	//Verificar si se creo bien la ventana
	if (!window) {
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecer "window" como contexto
	glfwMakeContextCurrent(window);

	//se trae las funciones de OpenGL Moderno
	glewExperimental = true;
	//Inicializar GLEW
	GLenum glewError = glewInit();
	//Verificar que GLEW se inicializo bien
	if (glewError != GLEW_OK) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}


	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGL: " << version << endl;

	red = green = blue = 0.0f;

	//glfwSetKeyCallback(window, key_callback);

	tiempoAnterior = glfwGetTime();

	//Ciclo de dibujo
	while (!glfwWindowShouldClose(window)) {
		//Establecer el area de render(Vewport)
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia la pantalla

	
		glClearColor(red, green, blue, 1);
		
		//Limpiar pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//rutina de dibujo
		actualizar();
		dibujar();

		//Intercambio de buffers
		glfwSwapBuffers(window);
		//Buscar señales de entrada
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

