#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main();
void addrec();
void read();
void giverec();
void recommend();
void logo(char []);
void displayHealthSaying();

struct food{
    char name[50];
    float calo;
};

struct get{
    char na[50];
    float gm;
    float cal;
};

void logo(char a[])
{
FILE *fp1; //fp1 for logo 
fp1=fopen(a,"r");
char ch;
while((ch = fgetc(fp1)) != EOF)
{
printf("%c", ch);
}
fclose(fp1);
}

void addrec()
{
	system("cls");
	displayHealthSaying();
    FILE *fp;
    struct food fo;
    char pw[50];
    int i,n;
    fp=fopen("foodref.txt","ab");
    printf("Enter the password");
    scanf("%s",&pw);
    if (strcmp(pw,"123@admin")!=0)
	{
        printf("Error!Password mismatch");
        exit(1);
    }
    printf("Enter the number of food to write:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
	{
        printf("Enter for food item %d\n",i+1);
        printf("Enter the name of the food\n");
        scanf("%s",&fo.name);
        printf("\nEnter the amount of calories per 100 gm\n");
        scanf("%f",&fo.calo);
        fwrite(&fo,sizeof(struct food),1,fp);
    }
    printf("File written!");
    fclose(fp);
    main();
}


void read()
{
	system("cls");
	displayHealthSaying();
	FILE *fp;
	struct food fo;
	fp=fopen("foodref.txt","rb");
	printf("\nName\tCalories(/100gm)\n");
	while(!feof(fp)){
		fread(&fo,sizeof(struct food),1,fp);
		if(!feof(fp))
		printf("%s\t%f\n",fo.name,fo.calo);
	}
	fclose(fp);
	main();
}



void giverec()
{
	system("cls");
	displayHealthSaying();
    //user gives food data data
    FILE *up;
    int i,ns;
	float x=0;
    up=fopen("userfood.txt","ab+");
    printf("Enter the number of food you want to check");
    scanf("%d",&ns);
    
    struct get ufo[ns];
    printf("\nEnter the data\n");
        for(i=0;i<ns;i++)
		{
        printf("Enter for food item %d\n",i+1);
        printf("Enter the name of the food\n");
        scanf("%s",&ufo[i].na);
        printf("Enter the weight of food(in gram)\n");
        scanf("%f",&ufo[i].gm);
		
	    FILE *fp;
	    struct food fo;
	    fp=fopen("foodref.txt","rb");
	    
	    while(!feof(fp))
	    {	
	    	fread(&fo,sizeof(struct food),1,fp);
	    	
	    	if(strcmp(ufo[i].na,fo.name)==0)
			{
				ufo[i].cal=(ufo[i].gm*fo.calo)/100;
				x=x+ufo[i].cal;
				fwrite(&ufo[i],sizeof(ufo),1,up);
				printf("The calorie of %f gm amount of %s is %f:\n",ufo[i].gm,ufo[i].na,ufo[i].cal);
			}
		}
	printf("The total calorie is %f:\n",x);
		fclose(fp);	
    }
    printf("The total calorie is %f:",x);
    fclose(up);
    main();
}



void recommend()
{	
	system("cls");
	displayHealthSaying();
    double weight, age;
    char gender;
    int activityLevel;

    printf("Enter your weight (kg): ");
    scanf("%lf", &weight);

    printf("Enter your age: ");
    scanf("%lf", &age);

    printf("Enter your gender (M/F): ");
    scanf(" %c", &gender);

    printf("Enter your activity level (1-5):\n");
    printf("1: Sedentary\n2: Lightly active\n3: Moderately active\n");
    printf("4: Very active\n5: Super active\n");
    scanf("%d", &activityLevel);

    double bmr;
    
    if (gender == 'M' || gender == 'm')
	{
        bmr = 88.362 + (13.397 * weight) + (4.799 * age) - (5.677 * age);
    } else if (gender == 'F' || gender == 'f') {
        bmr = 447.593 + (9.247 * weight) + (3.098 * age) - (4.330 * age);
    } else {
        printf("Invalid gender input\n");
        exit(1); // Return an error code
    }

    double activityFactor;

    switch (activityLevel) 
	{
        case 1:
            activityFactor = 1.2; // Sedentary (little to no exercise)
            break;
        case 2:
            activityFactor = 1.375; // Lightly active
            break;
        case 3:
            activityFactor = 1.55; // Moderately active
            break;
        case 4:
            activityFactor = 1.725; // Very active
            break;
        case 5:
            activityFactor = 1.9; // Super active
            break;
        default:
            printf("Invalid activity level input\n");
            exit(1); // Return an error code
    }

    double recommendedCalories = bmr * activityFactor;

    printf("Your recommended daily calories: %.2lf\n", recommendedCalories);
main();
}


void displayHealthSaying()
 {
    const char *sayings[] = {
        "\t\t\tStay hydrated for good health.",
        "\t\t\tRegular exercise improves your well-being.",
        "\t\t\tRemember to get enough sleep for a healthy lifestyle.",
        "\t\t\tInclude a variety of fruits and vegetables in your diet.",
        "\t\t\tPractice mindfulness and manage stress.",
        "\t\t\tKeep your body active to boost your immune system."
        // Add more sayings as needed
    };

    int numSayings = sizeof(sayings) / sizeof(sayings[0]);

    srand(time(NULL)); // Seed the random number generator
    int randomIndex = rand() % numSayings;

    printf("Health Tip: %10s\n", sayings[randomIndex]);
}



int main()
{
	int n;
	system("cls");
	displayHealthSaying();
	//welcome good message
	char ast[500]="************************************************************************************************************************";
	printf("%-15s",ast);
	logo("welcome.txt");
	printf("\t\t\t\t\tWhat do you want to do\n");
	printf("\t\t\t\t\t1.Add food items\n");//admin main file
	printf("\t\t\t\t\t2.Write food items\n");//user
	printf("\t\t\t\t\t3.Display the name of foods we can calculate calorie for\n");
	printf("\t\t\t\t\t4.View your recommended amount of calorie intake\n");
	printf("\t\t\t\t\t5.To exit program\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			addrec();
		break;
		
		case 2:
			giverec();
		break;
		case 3:
			read();
			break;
			
		case 4:
			recommend();
			break;
			
		case 5:
			printf("Successful Exit!");
			exit(0);
		
		default:
			printf("Invalid choice");
	}
return 0;
}
