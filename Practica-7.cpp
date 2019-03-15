//
//  main.cpp
//  Practica-7
//
//  Created by alumno on 3/15/19.
//  Copyright © 2019 alumno. All rights reserved.
//

#include <GLUT/glut.h>
#include <stdlib.h>

int ejex= 1;
int ejey= 1;
int ejez= 5;



void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
    
}

void display(void)
{
    
    
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    glLoadIdentity ();             /* clear the matrix */
    /* viewing transformation  */
    //gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    gluLookAt ( ejex, ejey, ejez, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    glScalef (1.0, 2.0, 1.0);      /* modeling transformation */
    glutWireCube (1.0);
    glFlush();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode (GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 'a':
            ejex = (ejex + 10);
            glutPostRedisplay();
            break;
            
        case 'A':
            ejex = (ejex - 10);
            glutPostRedisplay();
            break;
            
        case 'b':
            ejey = (ejey + 10);
            glutPostRedisplay();
            break;
        
        case 'B':
            ejey = (ejey - 10);
            glutPostRedisplay();
            break;
        case 'c':
            ejez = (ejez + 10);
            glutPostRedisplay();
            break;
            
        case 'C':
            ejez = (ejez - 10);
            glutPostRedisplay();
            break;
            
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
