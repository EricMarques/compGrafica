#include <stdio.h> //Imput Output
#include "glut.h" //Janelas etc...

//Declaracoes das variaveis
GLint mover=0;
GLint movercarro=0;
GLint movercarro2=0;
GLint movercarro3=0;
GLint movermadeira=0;
GLint movermadeira1=0;
GLint movermadeira2=0;
GLint direcao=1;
GLint moversapox=0;
GLint moversapoy=0;
GLint tempo=0;
GLint lado=0;

//Desenha a pista
void Pista (){
	 //laterais pista
	glColor3f(1,1,1);        
    glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(8,0);
	glVertex2f(8,13);
	glVertex2f(21.95,0);
	glVertex2f(21.95,13);
    glEnd();
    
    glColor3f(1,1,1);        
    glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(12.7,0);
	glVertex2f(12.7,2);
	glVertex2f(12.7,3);
	glVertex2f(12.7,6);
	glVertex2f(12.7,7);
	glVertex2f(12.7,10);
	glVertex2f(12.7,11);
	glVertex2f(12.7,14);
	
	glVertex2f(17.4,0);
	glVertex2f(17.4,2);
	glVertex2f(17.4,3);
	glVertex2f(17.4,6);
	glVertex2f(17.4,7);
	glVertex2f(17.4,10);
	glVertex2f(17.4,11);
	glVertex2f(17.4,14);
	
    glEnd();
    
    glColor3f(0,0.5,0);
    //Gramado
    glBegin(GL_QUADS);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 13.0);
    glVertex2f(8.0, 13.0);
    glVertex2f(8.0, 0.0);
    glEnd(); 
    
    glColor3f(0,0.5,0);
    //Gramado
    glBegin(GL_QUADS);
    glVertex2f(22.0, 0.0);
    glVertex2f(22.0, 13.0);
    glVertex2f(30.0, 13.0);
    glVertex2f(30.0, 0);
    glEnd();         
}

//Desenha o CARRO     
void Carro (){  
    glColor3f(0.5,0.5,0.5);         
    glPointSize(20.0);
    glBegin(GL_POINTS);        
    glVertex2f (moversapox+15,moversapoy+1);  
    glEnd();        
     
    glColor3f(1,1,0);         
    glPointSize(2.0);
    glBegin(GL_POINTS);        
    glVertex2f (moversapox+14.8,moversapoy+1.25);  //Farol esquerdo
    glVertex2f (moversapox+15.25,moversapoy+1.25);  //Farol direito
	glEnd(); 
	
	glColor3f(0.5,0.5,0); 
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glVertex2f (moversapox+14.5,moversapoy+1.15);  //Roda Dianteiro esquerda
	glVertex2f (moversapox+15.5,moversapoy+1.15);  //Roda Dianteira direita
	glEnd();
	glPointSize(7.0);
	glBegin(GL_POINTS);
    glVertex2f (moversapox+14.5,moversapoy+0.85);  //Roda Traseira esquerda
	glVertex2f (moversapox+15.5,moversapoy+0.85);  //Roda Traseira direita
    glEnd();          
}
 
//Desenha o CarroContrario1
void CarroContrario1 (){    
    glColor3f(0.5,1,0);
    glPointSize(20.0);
    glBegin(GL_POINTS);        
    glVertex2f (movercarro+1.5,3.5);        
    glEnd();
	glColor3f(0.5,0.5,0); 
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glVertex2f (moversapox+14.5,moversapoy+1.15);  //Roda Dianteiro esquerda
	glVertex2f (moversapox+15.5,moversapoy+1.15);  //Roda Dianteira direita
	glEnd();
	glPointSize(7.0);
	glBegin(GL_POINTS);
    glVertex2f (moversapox+14.5,moversapoy+0.85);  //Roda Traseira esquerda
	glVertex2f (moversapox+15.5,moversapoy+0.85);  //Roda Traseira direita
    glEnd();           
}

//Desenha o CarroContrario2
void CarroContrario2 (){
    glPointSize(20.0);
    glColor3f(0,0,0.5);
    glBegin(GL_POINTS);              
    glVertex2f (movercarro2+3.5,5.5);  
    glEnd();      
}

/*//Desenha o CarroContrario3
void CarroContrario3 (){    
    glPointSize(20.0);
    glColor3f(1,0,0);
    glBegin(GL_POINTS);              
    glVertex2f (movercarro2+6.5,5.5);  
    glEnd();  
}*/
     
//Movimentação automatica apenas ir 
void movimentacarro(int passo){ //Carro verde (CarroContrario1)
    {
    movercarro -= 4;
    if(movercarro == -8){
    movercarro = 36;
    }
    glutPostRedisplay();
    glutTimerFunc(100-tempo,movimentacarro, 1);
    }
}
     
void movimentacarro2(int passo){ //Carro azul (CarroContrario2)
    {
    movercarro2 -= 4;
    if(movercarro2 == -8){
    movercarro2 = 32;
    }
    glutPostRedisplay();
    glutTimerFunc(100-tempo,movimentacarro2, 1);
    }
}

/*void movimentacarro3(int passo){ //Carro vermelho (CarroContrario3)
    {
    movercarro3 -= 4;
    if(movercarro3 == -8){
    movercarro3 = 30;
    
    {
    movermadeira += 2;
    if(movermadeira == 36){
     movermadeira = -4;
    }
    glutPostRedisplay();
    glutTimerFunc(100-tempo,movermad, 1);
    }
}       
    glutPostRedisplay();
    glutTimerFunc(100-tempo,movimentacarro3, 1);
    }
} */
         
//Caso o carro passe por cima do sapo, retornar ao inicio     
void Colisao (){
     if ((mover-10 == moversapox+1) && (2 == moversapoy+1)) moversapoy = 0;
     if ((mover-10 == moversapox+2) && (2 == moversapoy+1)) moversapoy = 0;
     if ((mover-10 == moversapox+3) && (2 == moversapoy+1)) moversapoy = 0;
     if ((mover-10 == moversapox+4) && (2 == moversapoy+1)) moversapoy = 0;

     if ((movercarro-10 == moversapox+1) && (4 == moversapoy+1)) moversapoy = 0;
     if ((movercarro-10 == moversapox+2) && (4 == moversapoy+1)) moversapoy = 0;
     if ((movercarro-10 == moversapox+3) && (4 == moversapoy+1)) moversapoy = 0;
     if ((movercarro-10 == moversapox+4) && (4 == moversapoy+1)) moversapoy = 0;

     if ((movercarro2-10 == moversapox+1) && (6 == moversapoy+1)) moversapoy = 0;
     if ((movercarro2-10 == moversapox+2) && (6 == moversapoy+1)) moversapoy = 0;
     if ((movercarro2-10 == moversapox+3) && (6 == moversapoy+1)) moversapoy = 0;
     if ((movercarro2-10 == moversapox+4) && (6 == moversapoy+1)) moversapoy = 0;

     if ((7 == moversapoy+1) && (lado == 0)) lado = 1;  //Mudanca de lado
     if ((7 == moversapoy+1) && (lado == 2)) lado = 3;  //Mudanca de lado
     if ((7 == moversapoy+1) && (lado == 4)) lado = 5;  //Mudanca de lado
              
     glutPostRedisplay();
}
     
//Caso o sapo caia da madeira ou na agua, retornar ao inicio   
void Colisao1 (){
     if ((movermadeira-10 <= moversapox+0) && (6 == moversapoy+1)) moversapoy = 6;
     if ((movermadeira-10 >= moversapox+5) && (6 == moversapoy+1)) moversapoy = 6;
     if ((movermadeira-10 == moversapox+1) && (6 == moversapoy+1)) moversapox = movermadeira-12;    
     if ((movermadeira-10 == moversapox+2) && (6 == moversapoy+1)) moversapox = movermadeira-12;     
     if ((movermadeira-10 == moversapox+3) && (6 == moversapoy+1)) moversapox = movermadeira-12;  
     if ((movermadeira-10 == moversapox+4) && (6 == moversapoy+1)) moversapox = movermadeira-12;  
     if ((movermadeira == 24) && (6 == moversapoy+1)) moversapox = 0;     
     if ((movermadeira == 24) && (6 == moversapoy+1)) moversapoy = 6;     

     if ((movermadeira1-10 <= moversapox+0) && (4 == moversapoy+1)) moversapoy = 6;
     if ((movermadeira1-10 >= moversapox+5) && (4 == moversapoy+1)) moversapoy = 6;
     if ((movermadeira1-10 == moversapox+1) && (4 == moversapoy+1)) moversapox = movermadeira1-13;    
     if ((movermadeira1-10 == moversapox+2) && (4 == moversapoy+1)) moversapox = movermadeira1-13;     
     if ((movermadeira1-10 == moversapox+3) && (4 == moversapoy+1)) moversapox = movermadeira1-13;  
     if ((movermadeira1-10 == moversapox+4) && (4 == moversapoy+1)) moversapox = movermadeira1-13;  
     if ((movermadeira1 == 2) && (4 == moversapoy+1)) moversapox = 0;     
     if ((movermadeira1 == 2) && (4 == moversapoy+1)) moversapoy = 6;         
     
     if ((movermadeira2-10 <= moversapox+0) && (2 == moversapoy+1)) moversapoy = 6;
     if ((movermadeira2-10 >= moversapox+5) && (2 == moversapoy+1)) moversapoy = 6;
     if ((movermadeira2-10 == moversapox+1) && (2 == moversapoy+1)) moversapox = movermadeira2-13;    
     if ((movermadeira2-10 == moversapox+2) && (2 == moversapoy+1)) moversapox = movermadeira2-13;     
     if ((movermadeira2-10 == moversapox+3) && (2 == moversapoy+1)) moversapox = movermadeira2-13;  
     if ((movermadeira2-10 == moversapox+4) && (2 == moversapoy+1)) moversapox = movermadeira2-13;  
     if ((movermadeira2 == 2) && (2 == moversapoy+1)) moversapox = 0;     
     if ((movermadeira2 == 2) && (2 == moversapoy+1)) moversapoy = 6;     
              
     if ((1 == moversapoy+1) && (lado == 1)) lado = 2;  //Mudanca de lado
     if ((1 == moversapoy+1) && (lado == 3)) lado = 4;  //Mudanca de lado 
     if ((1 == moversapoy+1) && (lado == 5)) lado = 6;  //Mudanca de lado  
     
     glutPostRedisplay();     
}
//Comentario final
void Comentarios1 (){        
    {         
    glColor3f(1,1,1);
    glRasterPos2f(9.2, 6.0);         
    char* p = (char*) "Parabens!! Voce Ganhou!!";
    while (*p != '\0')
        {   
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
        }
    }   
}
     
//Chama o desenho
void Desenha(void){
	//Limpa a janela de visualização com a cor de fundo especificada 
    if(lado == 0){
    tempo = 40;  //Nivel 1, velocidade dos carros   
    glClear(GL_COLOR_BUFFER_BIT);
    Pista();
    Colisao();
    CarroContrario1();
    CarroContrario2();
    Carro();
    glutSwapBuffers();
    }
    if(lado == 1){
    tempo = 30;  //Nivel 1, velocidade do tronco
    glClear(GL_COLOR_BUFFER_BIT);
    Colisao1();
    CarroContrario1();
    CarroContrario2();
    //Caminhaos();
    }
    
    if(lado == 2){
    tempo = 55;  //Nivel 2, velocidade dos carros        
    glClear(GL_COLOR_BUFFER_BIT);
    Pista();
    Colisao();
    CarroContrario1();
    CarroContrario2();
    Carro();
    glutSwapBuffers();
    }
    if(lado == 3){
    tempo = 45;  //Nivel 2, velocidade do tronco       
    glClear(GL_COLOR_BUFFER_BIT);
    CarroContrario1();
    CarroContrario2();
    glutSwapBuffers();  
    }      
    if(lado == 4){
    tempo = 70;  //Nivel 3, velocidade dos carros        
    glClear(GL_COLOR_BUFFER_BIT);
    Pista();
    Colisao();
    CarroContrario1();
    CarroContrario2();
    Carro();
    glutSwapBuffers();
    }
    if(lado == 5){
    tempo = 60;  //Nivel 3, velocidade do tronco      
    glClear(GL_COLOR_BUFFER_BIT);
    Colisao1();
    Carro();
    glutSwapBuffers();  
    }  

    if(lado == 6){ //Final
    glClear(GL_COLOR_BUFFER_BIT);
    Comentarios1();
    glutSwapBuffers();  
    }             
}

//Funcoes para teclado (atribuicoes de teclas especiais)   
void Mover (int key, int x, int y){	
     if(key == GLUT_KEY_UP)      { moversapoy += 1; }
	 if(key == GLUT_KEY_DOWN)    { moversapoy -= 1; }
	 if(key == GLUT_KEY_LEFT)    { moversapox -= 1; }
	 if(key == GLUT_KEY_RIGHT)   { moversapox += 1; }

     //Limitando o sapo, para nao sair da tela
	 if (moversapoy < 0)   		 { moversapoy = 0;  } 
	 if (moversapoy > 6)         { moversapoy = 6;  }
     if (moversapox < -13)       { moversapox = -13;}
     if (moversapox > 13)        { moversapox = 13; }
     }          
     
//Funcoes para teclado (atribuicoes de teclas)   
void Teclado ( unsigned char key, int x, int y ){   
	 //Tela cheia na tecla f
	 if(key == 102)        { glutFullScreen(); }
     //Redesenha o novo valor 
     glutPostRedisplay();
     //Sai ao se precionar a tecla esc
     //if(key == 27){   exit(0); }
} 

//Define configuracoes da janela     
void Inicializa (void){   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h){
	GLsizei largura, altura;

	// Evita a divisao por zero
	if(h == 0) h = 1;

	// Atualiza as variáveis
	largura = w;
	altura = h;

	// Especifica as dimensões da Viewport
	glViewport(0, 0, largura, altura);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (esquerda, direita, inferior, 
	// superior) mantendo a proporção com a janela de visualização
	if (largura <= altura) 
		gluOrtho2D (0.0f, 23.0f, 0.0f*altura/largura, 13.0f*altura/largura);
	else 
		gluOrtho2D (0.0f*largura/altura, 23.0f*largura/altura, 0.0f, 13.0f);
}

//Chamada do main
int main(void){
    //Chamada para o OpenGL
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //Modo para nao exibir rastros na tela
    glutInitWindowSize (690, 530); //Tamanho da janela
    glutInitWindowPosition (50, 50);  //Localizacao inicial da janela
	glutCreateWindow("Enduro"); //Nome da janela
    glutKeyboardFunc(Teclado); //Chama as funcoes do teclado
    glutSpecialFunc(Mover);  //Chama as funcoes especias do teclado (setas de movimento)
	Inicializa(); 
	glutDisplayFunc(Desenha); //Chama o desenho
	glutReshapeFunc(AlteraTamanhoJanela); //Correcao de largura e altura para a janela
    //glutTimerFunc(10,movimentar,1);       //Chamada de movimento do carro
    glutTimerFunc(10,movimentacarro,1);   //Chamada de movimento do carro
    glutTimerFunc(10,movimentacarro2,1);  //Chamada de movimento do carro
    //glutTimerFunc(10,movimentacarro3,1);  //Chamada de movimento do carro
	glutMainLoop();
	//Final das funcoes do OpenGL
}   
