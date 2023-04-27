#include "../includes/shadersUtils.h"

#include <fstream>
#include <iostream>
using namespace std;


#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "../includes/gutils.h"
#include "../includes/logging.h"

char* loadCodeFromFile(codes code) {

	logging* logger = logging::getInstance();
	FILE *f;
    //ifstream file;
	if (code == codes::vertexCode) 
	{
		f = fopen(DEFAULT_VERTEX_SHADER_PATH, "r");
	}
	else if (code == codes::fragmentCode)
	{
        f = fopen(DEFAULT_FRAGMENT_SHADER_PATH, "r");
	}
    if(f == NULL)
    {
        cout << "Não abriu o arquivo." << endl;
        perror("Erro abrindo arquivo!");
    } else
    {
		logger->log(INFO, "Abriu o arquivo shader. Ponteiro aponta para ");
        cout << f << endl;
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
    cout << "Início do código do " << ((code == codes::vertexCode)? "Vertex" : "Fragment") << "Shader" << endl;
	logger->log(DEBUG, string);
	return string;
}



char* loadCodeFromFile(char* path) {
	FILE *f;
    //ifstream file;
	f = fopen(path, "r");
	
    if(f == NULL)
    {
        cout << "Não abriu o arquivo." << endl;
        perror("Erro abrindo arquivo!");
    } else
    {
        cout << "Abriu o arquivo shader. Ponteiro aponta para " << f << endl;
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
    cout << "\n ----------- Início do código do Shader ----------- \n" << string << endl;
	return string;
}
