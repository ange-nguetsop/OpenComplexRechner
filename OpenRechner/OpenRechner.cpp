#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define pi 3.14159265
#pragma warning (disable: 4996)

struct cmplx
{
    double real;
    double imag;
};
// Struktur, um Variablen zu speichern
struct Variable 
{
    char name[10];
    cmplx value;
};

// Struktur, um Variablen zu speichern
struct Datum {
    char name [10];
    double value;
};

// Eine Funktion, die Variablen nach Namen sucht und deren Werte zurückgibt Argument|Betrag
double getVariableValue(struct Datum* variables, char name[])
{
    for (int i = 0; strcmp(variables[i].name, "") != 0; i++) 
    {
        if (strcmp(variables[i].name ,name) == 0) 
        {
            return variables[i].value;
        }
    }
    printf("Fehler: Variable '%s' wurde nicht gefunden.\n", name);
    exit(EXIT_FAILURE);
}

// Eine Funktion, um Variablen zu aktualisieren oder zu erstellen Argument|Betrag
void setVariableValue(struct Datum* variables, char name[], double value) 
{
    for (int i = 0; strcmp(variables[i].name, "") != 0; i++) {
        if (strcmp(variables[i].name , name) == 0) 
        {
            variables[i].value = value;
            return;
        }
    }
    // Wenn die Variable nicht gefunden wurde, füge sie hinzu
    for (int i = 0; ; i++) {
        if (strcmp(variables[i].name, "") == 0) {
            strcpy(variables[i].name , name);
            variables[i].value = value;
            return;
        }
    }
}

// Eine Funktion, die Variablen nach Namen sucht und deren Werte zurückgibt
cmplx getVariableValue(struct Variable* variables, char name[])
{
    for (int i = 0; strcmp(variables[i].name ,"") != 0; i++) 
    {
        if (strcmp(variables[i].name , name) == 0) {
            return variables[i].value;
        }
    }

    printf("Fehler: Variable '%s' wurde nicht gefunden.\n", name);
    return { 0.0,0.0 };
   // exit(EXIT_FAILURE);
}

// Eine Funktion, um Variablen zu aktualisieren oder zu erstellen
void setVariableValue(struct Variable* variables, char name[], double real = 0, double imag = 0)
{
    for (int i = 0; strcmp(variables[i].name, "") != 0; i++) {
        if (strcmp(variables[i].name, name) == 0)
        {
            variables[i].value.real = real;
            variables[i].value.imag = imag;
            return;
        }
    }
    // Wenn die Variable nicht gefunden wurde, füge sie hinzu
    for (int i = 0; ; i++) {
        if (strcmp(variables[i].name, "") == 0)
        {
            strcpy(variables[i].name, name);
            variables[i].value.real = real;
            variables[i].value.imag = imag;
            return;
        }
    }
}

bool searchVariable(struct Variable* variables, char name[])
{
    for (int i = 0; strcmp(variables[i].name, "") != 0; i++)
    {
        if (strcmp(variables[i].name, name) == 0) {
            return true;
        }
    }
    return false;
}

cmplx operator+(cmplx kzahl1, cmplx kzahl2)
{
    cmplx res;
    res.real = kzahl1.real + kzahl2.real;
    res.imag = kzahl1.imag + kzahl2.imag;

    return res;
}

cmplx operator-(cmplx kzahl1, cmplx kzahl2)
{
    cmplx res;
    res.real = kzahl1.real - kzahl2.real;
    res.imag = kzahl1.imag - kzahl2.imag;

    return res;
}

cmplx operator*(cmplx z)
{
    cmplx res;
    res.real = z.real;
    res.imag = (-1) * z.imag;

    return res;
}

cmplx operator*(cmplx z1, cmplx z2)
{
    cmplx res;
    res.real = z1.real * z2.real - z1.imag * z2.imag;
    res.imag = z1.real * z2.imag + z2.real * z1.imag;

    return res;
}

cmplx operator/(cmplx z1, cmplx z2)
{
    cmplx res;
    res.real = (z1.real * z2.real + z1.imag * z2.imag) / ((z2.real * z2.real) + (z2.imag * z2.imag));
    res.imag = (z2.real * z1.imag - z1.real * z2.imag) / ((z2.real * z2.real) + (z2.imag * z2.imag));

    return res;
}

void druecke(cmplx z)
{
    if (z.imag < 0)
    {
        printf("%.2lf - j%.2lf\n\n", z.real, (-1) * z.imag);
    }
    else
    {
        printf("%.2lf + j%.2lf\n\n", z.real, z.imag);
    }
}

double betrag(cmplx z)
{
    double res;
    res = sqrt((z.real * z.real) + (z.imag * z.imag));

    return res;
}

double argument(cmplx z)
{
    if (z.real > 0)
    {
        return atan2(z.imag, z.real);
    }
    else if (z.real == 0 && z.imag > 0)
    {
        return pi / 2;
    }
    else if (z.real < 0)
    {
        return (pi + atan2(z.imag, z.real));
    }
    else if (z.real == 0 && z.imag < 0)
    {
        return (3 * pi / 2);
    }
    else
    {
        return 0;
    }
}

void newlineLoeschen(char* chaine)
{
    int count = 0;
    for (int i = 0; chaine[i]; i++)
    {
        if (chaine[i] != ' ')
        {
            chaine[count++] = chaine[i];
        }
    }
    chaine[count] = '\0';

    size_t len = strlen(chaine);
    if (len > 0 && (chaine[len - 1] == '\n'))
    {
        chaine[len - 1] = '\0'; // Entfernt das Zeichen '\n' am Ende des Strings
    }

}

void newline(char* chaine)
{
    size_t len = strlen(chaine);
    if (len > 0 && (chaine[len - 1] == '\n'))
    {
        chaine[len - 1] = '\0'; // Entfernt das Zeichen '\n' am Ende des Strings
    }
}

double safeAtof(const char* str) 
{
    char* endptr;
    double result = strtod(str, &endptr);

    // Check if the entire string was parsed, and if not, return 0.0
    if (*endptr != '\0') {
        result = 0.0;
    }

    return result;
}

int main(void)
{
    char input[100];
    struct Variable var[100] = { 0 };
    struct Datum Var[100] = { 0 };


    printf("\t\t\t\tKOMPLEXE ZAHLEN RECHNER\n");
    printf("\t\t\t\t===========================\n\n");

    printf("Eine komplexe Zahl ist ein geordnetes Paar von zwei reellen Zahlen (a,b)\n");
    printf("-> a wird als der Realteil von (a,b) bezeichnet\n");
    printf("-> b wird als der Imaginaerteil von (a,b) bezeichnet\n");
    printf("Um eine komplexe Zahl darzustellen, verwenden wir die algebraische Notation, z = a + jb mit j\^2 = -1\n");
    printf("Mit dem online-Rechner fuer komplexe Zahlen koennen Sie folgende Operationen durchfuehren:\n\n");
    printf("-> Addition z.B z1 + z2 \n");
    printf("-> Subtraktion z.B z1 - z2 \n");
    printf("-> Multiplikation z.B z1 * z2 \n");
    printf("-> Division z.B z1 / z2 \n");
    printf("-> Argument, Betrag und konjugierte Form \n");
    printf("-> Fuer Hilfe geben Sie 'help' ein \n\n");

    while (1)
    {
    L1:
        bool var1 = false;
        char name[100];
        double real = 0, imag = 0;
        char special = '=';
        char espace = ' ';
        printf(">> ");
        fgets(input, sizeof(input), stdin);
        if (strstr(input, ";") != NULL) var1 = true;
        newline(input);
        if (strncmp(input, "exit", 4) == 0)
        {
            break;
        }
        else if (searchVariable(var, input))
        {
            newlineLoeschen(input);
            strcpy(name, input);
            cmplx zahl = getVariableValue(var, name);
            printf("%s = ", name);
            druecke(zahl);
        }
        else if (strstr(input, "j") != NULL && sscanf(input, "%s = %lf %*c j %lf", name, &real, &imag) == 3)
        {
   
            char varName[10];
            bool var2 = false;
            char* token = NULL;
            int count = 0;
            if (strstr(input, "-") != NULL) var2 = true;
            token = strtok(input, "=+-j; ");
            while (token != NULL)
            {
                newlineLoeschen(token);
                switch (count)
                {
                case 0:
                    strcpy(varName, token);
                    break;
                case 1:
                    real = atof(token);
                    if (atof(token) == 0.0)
                    {
                        printf("Ungueltige Eingabe\n");
                        goto L1;
                    }
                    break;
                case 2:
                    imag = atof(token);
                    if (atof(token) == 0.0)
                    {
                        printf("Ungueltige Eingabe\n");
                        goto L1;
                    }
                    break;
                }
                token = strtok(NULL, "=+-j; ");
                count++;
            }
            if (var2 == true)
            {
                imag = (-1) * imag;
            }

            setVariableValue(var, varName, real, imag);

            if (var1 == false)
            {
                printf("%s = ", varName);
                druecke(getVariableValue(var, varName));
            }
        }

        else if (strstr(input, "*") != NULL)
        {

            if (strstr(input, "=") != NULL)
            {

                char res[10];
                char name[10];
                cmplx ans = { 0,0 };
                char* token = strtok(input, "=");
                newlineLoeschen(token);
                int count = 0;
                strcpy(res, token);
                while (token != NULL)
                {
                    token = strtok(NULL, " *;");

                    if (token != NULL)
                    {
                        strcpy(name, token);
                        newlineLoeschen(name);
                        if (count == 0)
                        {
                            if (atof(name) != 0.0)
                            {
                                double real = atof(name);
                                ans = { real,0.0 };
                            }
                            else if (strstr(name, "j") != NULL && searchVariable(var, name) == false)
                            {
                                double imag = strtod(name + 1, NULL);
                                ans = { 0.0,imag };
                            }
                            else
                                ans = getVariableValue(var, name);
                        }

                        else
                        {
                            if (atof(name) != 0.0)
                            {
                                double real = atof(name);
                                cmplx tmp = { real,0.0 };
                                ans = ans * tmp;
                            }
                            else if (strstr(name, "j") != NULL && searchVariable(var, name) == false)
                            {
                                double imag = strtod(name + 1, NULL);
                                cmplx tmp = { 0.0,imag };
                                ans = ans * tmp;
                            }
                            else
                                ans = ans * getVariableValue(var, name);
                        }

                    }
                    count++;
                }
                setVariableValue(var, res, ans.real, ans.imag);
                if (var1 == false)
                {
                    printf("%s = ", res);
                    druecke(ans);
                }


            }

            else
            {
                char ans[4] = "ans";
                char name[10];
                cmplx res = { 0,0 };
                int count = 0;
                char* token = strtok(input, " *;");
                while (token != NULL)
                {

                    if (token != NULL)
                    {
                        strcpy(name, token);
                        newlineLoeschen(name);
                        if (count == 0)
                        {

                            if (atof(name) != 0.0)
                            {
                                double real = atof(name);
                                res = { real,0.0 };
                            }
                            else if (strstr(name, "j") != NULL && searchVariable(var, name) == false)
                            {
                                double imag = strtod(name + 1, NULL);
                                res = { 0.0,imag };
                            }
                            else
                                res = getVariableValue(var, name);
                        }
                        else
                        {
                            if (atof(name) != 0.0)
                            {
                                double real = atof(name);
                                cmplx tmp = { real,0.0 };
                                res = res * tmp;
                            }
                            else if (strstr(name, "j") != NULL && searchVariable(var, name) == false)
                            {
                                double imag = strtod(name + 1, NULL);
                                cmplx tmp = { 0.0,imag };
                                res = res * tmp;
                            }
                            else
                                res = res * getVariableValue(var, name);
                        }

                        token = strtok(NULL, " *;");
                    }
                    count++;
                }
                setVariableValue(var, ans, res.real, res.imag);
                if (var1 == false)
                {
                    printf("%s = ", ans);
                    druecke(res);
                }

            }

        }

        else if (strstr(input, "/") != NULL)
        {

            if (strstr(input, "=") != NULL)
            {

                char res[10];
                char name[10];
                cmplx ans = { 0,0 };
                char* token = strtok(input, "=");
                newlineLoeschen(token);
                int count = 0;
                strcpy(res, token);
                while (token != NULL)
                {
                    token = strtok(NULL, " /;");
                    if (token != NULL)
                    {
                        newlineLoeschen(token);
                        strcpy(name, token);

                        if (count == 0)
                        {
                            if (atof(name) != 0.0)
                            {
                                double real = atof(name);
                                ans = { real,0.0 };
                            }
                            else if (strstr(name, "j") != NULL && searchVariable(var, name) == false)
                            {
                                double imag = strtod(name + 1, NULL);
                                ans = { 0.0,imag };
                            }
                            else
                                ans = getVariableValue(var, name);
                        }

                        else
                        {
                            if (atof(name) != 0.0)
                            {
                                double real = atof(name);
                                cmplx tmp = { real,0.0 };
                                ans = ans / tmp;
                            }
                            else if (strstr(name, "j") != NULL && searchVariable(var, name) == false)
                            {
                                double imag = strtod(name + 1, NULL);
                                cmplx tmp = { 0.0,imag };
                                ans = ans / tmp;
                            }
                            else
                                ans = ans / getVariableValue(var, name);
                        }
                        count++;
                    }
                }
                setVariableValue(var, res, ans.real, ans.imag);
                if (var1 == false)
                {
                    printf("%s = ", res);
                    druecke(ans);
                }


            }

            else
            {
                char ans[4] = "ans";
                char name[10];
                cmplx res = { 0,0 };
                int count = 0;
                char* token = strtok(input, " /;");
                while (token != NULL)
                {

                    if (token != NULL)
                    {
                        strcpy(name, token);
                        newlineLoeschen(name);
                        if (count == 0)
                        {

                            if (atof(name) != 0.0)
                            {
                                double real = atof(name);
                                res = { real,0.0 };
                            }
                            else if (strstr(name, "j") != NULL && searchVariable(var, name) == false)
                            {
                                double imag = strtod(name + 1, NULL);
                                res = { 0.0,imag };
                            }
                            else
                                res = getVariableValue(var, name);
                        }
                        else
                        {
                            if (atof(name) != 0.0)
                            {
                                double real = atof(name);
                                cmplx tmp = { real,0.0 };
                                res = res / tmp;
                            }
                            else if (strstr(name, "j") != NULL && searchVariable(var, name) == false)
                            {
                                double imag = strtod(name + 1, NULL);
                                cmplx tmp = { 0.0,imag };
                                res = res / tmp;
                            }
                            else
                                res = res / getVariableValue(var, name);
                        }

                        token = strtok(NULL, " *;");
                    }
                    count++;
                }
                setVariableValue(var, ans, res.real, res.imag);
                if (var1 == false)
                {
                    printf("%s = ", ans);
                    druecke(res);
                }

            }

            }

        else if (strstr(input, "+") != NULL)

        {
            printf("Je suis entree ici\n");

            if (strstr(input, "=") != NULL)
            {

                char res[10];
                cmplx ans = { 0,0 };
                char* token = strtok(input, "=+;");
                newlineLoeschen(token);
                strcpy(res, token);
                while (token != NULL)
                {
                    token = strtok(NULL, ";=+");

                    if (token != NULL && strcmp(token, "") != 0)
                    {
                        newlineLoeschen(token);

                        if (safeAtof(token) != 0.0)
                        {

                            cmplx tmp = { atof(token), 0.0 };
                            ans = ans + tmp;
                        }
                        else if (strstr(token, "j") != NULL && searchVariable(var, token) == false)
                        {
                            char op = 'c';
                            double real, imag;
                            if (sscanf(token, "(%lf - j%lf)", &real, &imag) == 2)
                            {
                                imag = (-1) * imag;
                                cmplx tmp = { real,imag };
                                ans = ans + tmp;
                            }
                            else if (sscanf(token, "(j%lf) ", &imag) == 1 || sscanf(token, "(%c j %lf) ", &op, &imag) == 2)
                            {

                                if (op == '-')
                                {
                                    imag = (-1) * imag;
                                }
                                cmplx zahl = { 0.0, imag };
                                ans = ans + zahl;
                            }
                            else
                            {
                                imag = strtod(token + 1, NULL);
                                cmplx tmp = { 0.0, imag };
                                ans = ans + tmp;
                            }

                        }
                        else if (sscanf(token, "(%lf)", &real) == 1 || sscanf(token, "%lf)", &real) == 1)
                        {
                            cmplx zahl = { real,0.0 };
                            ans = ans + zahl;
                        }

                        else if (strstr(token, "(") != NULL)
                        {
                            char name1[100], op = 'c';
                            double imag = 0, real = 0;
                            strcpy(name1, token + 1);
                            token = strtok(NULL, ")");
                            strcat(name1, token);
                            newlineLoeschen(name1);

                            if (safeAtof(name1) != 0.0)
                            {

                                real = safeAtof(name1);
                                cmplx zahl = { real,0.0 };
                                ans = ans + zahl;
                            }
                            else if (sscanf(name1, "%lfj%lf", &real, &imag) == 2)
                            {

                                cmplx zahl = { real, imag };
                                ans = ans + zahl;
                            }
                            else if (sscanf(name1, "%lf %c j %lf", &real, &op, &imag) == 3)
                            {

                                if (op == '-')
                                {
                                    imag = (-1) * imag;
                                }
                                cmplx zahl = { real, imag };
                                ans = ans + zahl;
                            }


                        }
                        else
                        {

                            ans = ans + getVariableValue(var, token);
                        }

                    }

                }
                setVariableValue(var, res, ans.real, ans.imag);
                if (var1 == false)
                {
                    printf("%s = ", res);
                    druecke(ans);
                }


            }

            else
            {
                char res[] = "ans";
                cmplx ans = { 0,0 };
                char* token = strtok(input, "+;");
                while (token != NULL)
                {
                    if (token != NULL)
                    {
                        newlineLoeschen(token);
                        if (safeAtof(token) != 0.0)
                        {
                            cmplx tmp = { atof(token), 0.0 };
                            ans = ans + tmp;
                        }
                        else if (strstr(token, "j") != NULL && searchVariable(var, token) == false)
                        {
                            char op = 'c';
                            if (sscanf(token, "(%lf - j%lf)", &real, &imag) == 2)
                            {

                                imag = (-1) * imag;
                                cmplx tmp = { real,imag };
                                ans = ans + tmp;
                            }
                            else if (sscanf(token, "(j%lf) ", &imag) == 1 || sscanf(token, "(%c j %lf) ", &op, &imag) == 2)
                            {

                                if (op == '-')
                                {
                                    imag = (-1) * imag;
                                }
                                cmplx zahl = { 0.0, imag };
                                ans = ans + zahl;
                            }
                            else
                            {
                                imag = strtod(token + 1, NULL);
                                cmplx tmp = { 0.0, imag };
                                ans = ans + tmp;
                            }

                        }
                        else if (sscanf(token, "(%lf)", &real) == 1 || sscanf(token, "%lf)", &real) == 1)
                        {
                            cmplx zahl = { real,0.0 };
                            ans = ans + zahl;
                        }

                        else if (strstr(token, "("))
                        {
                            char name[100], op = 'c';
                            double imag = 0, real = 0;
                            strcpy(name, token + 1);
                            token = strtok(NULL, ")");
                            strcat(name, token);
                            newlineLoeschen(name);

                            if (safeAtof(name) != 0.0)
                            {
                                real = safeAtof(name);
                                cmplx zahl = { real,0.0 };
                                ans = ans + zahl;
                            }
                            else if (sscanf(name, "%lfj%lf", &real, &imag) == 2)
                            {
                                cmplx zahl = { real, imag };
                                ans = ans + zahl;
                            }
                            else if (sscanf(name, "%lf %c j %lf", &real, &op, &imag) == 3)
                            {
                                if (op == '-')
                                {
                                    imag = (-1) * imag;
                                }
                                cmplx zahl = { real, imag };
                                ans = ans + zahl;
                            }



                        }
                        else
                            ans = ans + getVariableValue(var, token);
                    }

                    token = strtok(NULL, "+;");

                }
                setVariableValue(var, res, ans.real, ans.imag);
                if (var1 == false)
                {
                    printf("%s = ", res);
                    druecke(ans);
                }
            }

            }

        else if (strstr(input, "-") != NULL)
        {

            if (strstr(input, "=") != NULL)
            {

                char res[10];
                char name[10];
                cmplx ans = { 0,0 };
                char* token = strtok(input, "=");
                newlineLoeschen(token);
                int count = 0;
                strcpy(res, token);
                while (token != NULL)
                {
                    token = strtok(NULL, " -;");

                    if (token != NULL)
                    {
                        strcpy(name, token);
                        newlineLoeschen(name);
                        printf("token: %s\n", name);
                        if (count == 0)
                        {
                            if (safeAtof(name) != 0.0)
                            {
                                double real = atof(name);
                                ans = { real,0.0 };
                            }
                            else if (strstr(name, "j") != NULL && searchVariable(var, name) == false)
                            {
                                // double imag = strtod(name + 1, NULL);
                                 // ans = { 0.0,imag };
                                char op = 'c';
                                double real, imag;
                                if (sscanf(token, "(%lf + j%lf)", &real, &imag) == 2)
                                {
                                    imag = (-1) * imag;
                                    cmplx tmp = { real,imag };
                                    ans = ans + tmp;
                                }
                                else if (sscanf(token, "(j%lf) ", &imag) == 1 || sscanf(token, "(%c j %lf) ", &op, &imag) == 2)
                                {

                                    if (op == '-')
                                    {
                                        imag = (-1) * imag;
                                    }
                                    cmplx zahl = { 0.0, imag };
                                    ans = ans + zahl;
                                }

                                else
                                {
                                    imag = strtod(token + 1, NULL);
                                    cmplx tmp = { 0.0, imag };
                                    ans = ans + tmp;
                                }
                            }

                            else if (sscanf(token, "(%lf)", &real) == 1 || sscanf(token, "%lf)", &real) == 1)
                            {
                                cmplx zahl = { real,0.0 };
                                ans = ans + zahl;
                            }

                            else if (strstr(token, "(") != NULL)
                            {
                                char name1[100], op = 'c';
                                double imag = 0, real = 0;
                                strcpy(name1, token + 1);
                                token = strtok(NULL, ")");
                                strcat(name1, token);
                                newlineLoeschen(name1);

                                if (safeAtof(name1) != 0.0)
                                {

                                    real = safeAtof(name1);
                                    cmplx zahl = { real,0.0 };
                                    ans = ans + zahl;
                                }
                                else if (sscanf(name1, "%lfj%lf", &real, &imag) == 2)
                                {

                                    cmplx zahl = { real, imag };
                                    ans = ans + zahl;
                                }
                                else if (sscanf(name1, "%lf %c j %lf", &real, &op, &imag) == 3)
                                {

                                    if (op == '-')
                                    {
                                        imag = (-1) * imag;
                                    }
                                    cmplx zahl = { real, imag };
                                    ans = ans + zahl;
                                }
                            }

                            else
                                ans = getVariableValue(var, name);
                        }

                        else
                        {
                            if (atof(name) != 0.0)
                            {
                                double real = atof(name);
                                cmplx tmp = { real,0.0 };
                                ans = ans - tmp;
                            }
                            else if (strstr(name, "j") != NULL && searchVariable(var, name) == false)
                            {
                                double imag = strtod(name + 1, NULL);
                                cmplx tmp = { 0.0,imag };
                                ans = ans - tmp;
                            }
                            else
                                ans = ans - getVariableValue(var, name);
                        }

                    }
                    count++;
                }
                setVariableValue(var, res, ans.real, ans.imag);
                if (var1 == false)
                {
                    printf("%s = ", res);
                    druecke(ans);
                }

            }

            else
            {
                char ans[4] = "ans";
                char name[10];
                cmplx res = { 0,0 };
                char* token = strtok(input, " -;");
                int count = 0;
                while (token != NULL)
                {

                    if (token != NULL)
                    {
                        strcpy(name, token);
                        newlineLoeschen(name);
                        if (count == 0)
                        {
                            if (atof(name) != 0.0)
                            {
                                double real = atof(name);
                                res = { real,0.0 };
                            }
                            else if (strstr(name, "j") != NULL && searchVariable(var, name) == false)
                            {
                                double imag = strtod(name + 1, NULL);
                                res = { 0.0,imag };
                            }
                            else
                                res = getVariableValue(var, name);
                        }
                        else
                        {
                            if (atof(name) != 0.0)
                            {
                                double real = atof(name);
                                cmplx tmp = { real,0.0 };
                                res = res - tmp;
                            }
                            else if (strstr(name, "j") != NULL && searchVariable(var, name) == false)
                            {
                                double imag = strtod(name + 1, NULL);
                                cmplx tmp = { 0.0,imag };
                                res = res - tmp;
                            }
                            else
                                res = res - getVariableValue(var, name);
                        }

                        token = strtok(NULL, " -;");
                    }
                    count++;
                }
                setVariableValue(var, ans, res.real, res.imag);
                if (var1 == false)
                {
                    printf("%s = ", ans);
                    druecke(res);
                }

            }

            }

        else if (strstr(input, "abs") != NULL)
        {
            if (strstr(input, "=") != NULL)
            {
                char name[10];
                char value[10];
                sscanf(input, "%s = %*s %s", name, value);
                newlineLoeschen(name);
                newlineLoeschen(value);
                double abs = betrag(getVariableValue(var, value));
                setVariableValue(Var, name, abs);
                if (var1 == false)
                {
                    printf("%s = %.3lf\n",name,abs);
                }
            }
            else
            {
                char ans[] = "ans";
                char value[10];
                sscanf(input, "%*s %s", value);
                newlineLoeschen(value);
                double res = betrag((getVariableValue(var, value)));
                setVariableValue(Var, ans, res);
                if (var1 == false)
                {
                    printf("ans = %.3lf\n", res);
                }

            }



        }
        else if (strstr(input, "arg") != NULL)
        {
            if (strstr(input, "=") != NULL)
            {
                char name[10];
                char value[10];
                sscanf(input, "%s = %*s %s", name, value);
                newlineLoeschen(name);
                newlineLoeschen(value);
                double arg = argument(getVariableValue(var, value));
                setVariableValue(Var, name, arg);

                if (var1 == false)
                {
                    printf("%s = %.3lf rad\n",name, arg);
                }
            }
            else
            {
                char ans[] = "ans";
                char value[10];
                sscanf(input, "%*s %s", value);
                newlineLoeschen(value);
                double res = argument((getVariableValue(var, value)));
                setVariableValue(Var, ans, res);
                if (var1 == false)
                {

                    printf("ans = %.3lf rad\n", res);
                }

            }
        }
        else if (strstr(input, "conj") != NULL)

        {

            if (strstr(input, "=") != NULL)
            {
                char name[10];
                char value[10];
                sscanf(input, "%s = %*s %s", name, value);
                newlineLoeschen(name);
                newlineLoeschen(value);
                cmplx conj = *(getVariableValue(var, value));
                setVariableValue(var, name, conj.real, conj.imag);
                if (var1 == false)
                {
                    printf("%s = ", name);
                    druecke(conj);
                }
            }
            else
            {
                char ans[] = "ans";
                char value[10];
                sscanf(input, "%*s %s", value);
                newlineLoeschen(value);
                cmplx res = *((getVariableValue(var, value)));
                setVariableValue(var, ans, res.real, res.imag);
                if (var1 == false)
                {
                    printf("%s = ", ans);
                    druecke(res);
                }

            }


        }
        else if (strstr(input, "help") != NULL)
        {
            printf("Dies ist ein einfacher komplexer Zahlenrechner, der folgende Operationen unterstuetzt:\n\n");

            printf("1. Zuweisung von komplexen Zahlen:\n");
            printf("   - Verwenden Sie die algebraische Notation, z.B. a = 3 + j4\n");
            printf("   - Beachten Sie, dass 'j' fuer den Imaginaerteil steht und 'j^2' als '-1' angenommen wird.\n\n");

            printf("2. Addition:\n");
            printf("   - Beispiel: ans = a + b\n");
            printf("   - Sie koennen auch ohne Zuweisung machen: a + b\n");
            printf("   - Fuehren Sie die Addition von zwei komplexen Zahlen aus und speichern Sie das Ergebnis in 'ans'.\n\n");

            printf("3. Subtraktion:\n");
            printf("   - Beispiel: ans = a - b\n");
            printf("   - Sie koennen auch ohne Zuweisung machen: a - b\n");
            printf("   - Fuehren Sie die Subtraktion von zwei komplexen Zahlen aus und speichern Sie das Ergebnis in 'ans'.\n\n");

            printf("4. Multiplikation:\n");
            printf("   - Beispiel: ans = a * b\n");
            printf("   - Sie koennen auch ohne Zuweisung machen: a * b\n");
            printf("   - Fuehren Sie die Multiplikation von zwei komplexen Zahlen aus und speichern Sie das Ergebnis in 'ans'.\n\n");

            printf("5. Division:\n");
            printf("   - Beispiel: ans = a / b\n");
            printf("   - Sie koennen auch ohne Zuweisung machen: a / b\n");
            printf("   - Fuehren Sie die Division von zwei komplexen Zahlen aus und speichern Sie das Ergebnis in 'ans'.\n\n");

            printf("6. Betrag einer komplexen Zahl:\n");
            printf("   - Beispiel: ans = abs( a )\n");
            printf("   - Sie koennen auch ohne Zuweisung machen: abs ( a )\n");
            printf("   - Berechnen Sie den Betrag (die absolute Wert) einer komplexen Zahl 'a' und speichern Sie das Ergebnis in 'ans'.\n\n");

            printf("7. Argument einer komplexen Zahl:\n");
            printf("   - Beispiel: ans = arg(a)\n");
            printf("   - Sie koennen auch ohne Zuweisung machen: arg ( a ) \n");
            printf("   - Berechnen Sie das Argument (den Winkel) einer komplexen Zahl 'a' und speichern Sie das Ergebnis in 'ans'.\n\n");

            printf("8. Ausgabe einer komplexen Zahl:\n");
            printf("   - Beispiel: ans = conj ( a )\n");
            printf("   - Sie koennen auch ohne Zuweisung machen: conj ( a ) \n");
            printf("   - Geben Sie die komplexen Zahl 'a' aus.\n\n");

            printf("9. Beenden des Programms:\n");
            printf("   - Beispiel: exit\n");
            printf("   - Beenden Sie das Programm.\n\n");

            printf("Hinweise:\n");
            printf("- Verwenden Sie Leerzeichen, um Ausdruecke zu trennen (z.B. 'a = 3 + j4')\n");
            printf("- Die Reihenfolge der Operationen wird von links nach rechts ausgewertet.\n");
            printf("- Die Hilfe ist ueber den Befehl 'help' verfuegbar.\n\n");
        }
        else if (strstr(input, "show variables") != NULL)
        {
            char* token = strtok(input, "'show' ");
            newlineLoeschen(token);
            cmplx z = getVariableValue(var, token);
            printf("%s = ", token);
            druecke(z);
        }
        else
        {
            printf("Ungueltige Eingabe.\n");
        }
    }

    return 0;
}