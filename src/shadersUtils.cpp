#include "../includes/shadersUtils.h"

#include <fstream>
#include <iostream>
using namespace std;


#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "../includes/gutils.h"

char* loadCodeFromFile(codes code) {
	FILE *f;
    //ifstream file;
	if (code == codes::vertexCode) 
	{
		f = fopen("src/vertex_code.vs", "r");
	}
	else if (code == codes::fragmentCode)
	{
        f = fopen("src/fragment_code.fs", "r");
	}
    if(f == NULL)
    {
        cout << "Não abriu o arquivo." << endl;
        perror("Erro abrindo arquivo!");
    } else
    {
        cout << "Abriu o arquivo. Ponteiro aponta para " << f << endl;
    }

    rewind(f);
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
    
    cout << "tamanho: " << fsize << endl;

	char *string = (char *)malloc(fsize + 1);
	fread(string, fsize, 1, f);
	fclose(f);


	string[fsize] = 0;
    cout << "Início do código do " << ((code == codes::vertexCode)? "Vertex" : "Fragment") << "Shader" << string << endl;
	return string;
}




