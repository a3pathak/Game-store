#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
//Global variables
int player1score=0,player2score=0, m=0, c=0;
int height=20,width=20,gameOver;
int x,y,fruitX,fruitY,score,flag;
int tailX[100],tailY[100],counttail=0;
char a[9]={'1','2','3','4','5','6','7','8','9'};
int k=0,end=1;
int score=0,sco=0;
int cash=100;
int bettingAmount;
//From here rock paper sessior game start
void menu()
{
	printf("\t\t\t..........................................\n");
	printf("\t\t\t.                                        .\n");
	printf("\t\t\t.......ROCK PAPER AND SESSIOR GAME........\n");
	printf("\t\t\t.                                        .\n");
	printf("\t\t\t..........................................\n");
	printf("\t\t\tPress 1 for rock\n");
	printf("\t\t\tPress 2 for paper\n");
	printf("\t\t\tPress 3 for sesior\n");
    printf("\t\t\tPress 4 for Score\n");
}
 void mainLogic()
 {
 	int b,ch;
    menu();
    printf("\t\t\tPlayer1 Enter your choise..");
    scanf("%d",&ch);
    system("cls");
    switch(ch)
	{
	    case 1:
	 	    printf("\t\t\tPlayer2 Enter your choise..");
            scanf("%d",&b);
		    if(b==1)
		    	printf("\t\t\tGame draw\n");
	    	else if(b==2)
		        {
		            printf("\t\t\tPlayer2 won\n");
		            player2score++;
	            }
		    else if(b==3)
		        {
		            printf("\t\t\tplayer1 won\n");
		            player1score++;
	            }
	     	else
		        printf("\t\t\tEnter a valid option\n");
	    break;
	    case 2:
	     	printf("\t\t\tPlayer2 Enter your choise..");
            scanf("%d",&b);
	    	if(b==1)
	        	{
		            printf("\t\t\tPlayer1 won\n"); 
		            player1score++;
	            }
		    else if(b==2)
		        printf("\t\t\tGame draw\n");
		    else if(b==3)
		        {
		            printf("\t\t\tPlayer2 won\n");
		            player2score++;
	            }
		    else
		        printf("\t\t\tEnter a valid option\n");
	    break;
	    case 3:
	    	printf("\t\t\tPlayer2 Enter your choise..");
            scanf("%d",&b);
	    	if(b==1)
		        {
		            printf("\t\t\tPlayer2 won\n");
		            player2score++;
	            }
		    else if(b==2)
		        {
		            printf("\t\t\tplayer1 won\n");
		            player1score++;
	            }
		    else if(b==3)
		        printf("\t\t\tGame draw\n");
		    else
		        printf("\t\t\tEnter a valid option\n");
	    break;
	    case 4:
	 	    printf("\t\t\tplayer1 score: %d\n",player1score);
	 	    if(m<player1score)
	 	    {
	 	    	m=player1score;
	 	    	printf("\t\t\tHigh score of player1: %d\n",m);
			}
			printf("\t\t\tplayer2 score: %d\n",player2score);
			if(c<player2score)
	 	    {
	 	    	c=player2score;
	 	    	printf("\t\t\tHigh score of player2: %d\n",c);
			}
	    break;
	    default:
		    printf("\t\t\tEnter a valid option\n");
	}
}
void rockPaperGame()
{
        label:
	    system("cls");
	    mainLogic();
	    printf("\t\t\tPress y to play again");
	    fflush(stdin);
	    scanf("%c",&c);
	    if(c=='y'||c=='Y')
	    goto label;
	    getch();
}
//From here snake game start
void setup()
{
	gameOver=0;
	x=width/2;
	y=height/2;
    label:
	fruitX=rand()%20;
	if(fruitX==0)
	goto label;
	label1:
	fruitY=rand()%20;
	if(fruitY==0)
	goto label1;
	score=0;
}
void draw()
{
	int i,j,k;
	system("cls");
	printf("..........................................\n");
	printf(".                                        .\n");
	printf("................SNAKE GAME................\n");
	printf(".                                        .\n");
	printf("..........................................\n");
	for(i=0;i<=height;i++)
	{
		for(j=0;j<=width;j++)
		{
			if(i==0||i==height||j==0||j==width)
			{
				printf("*");
			}
			else
			{
				label2:
				if(i==x && j==y)
    				printf("O");
				else if(i==fruitX && j==fruitY)
			    	printf("f");
				else
			    	{
			    		int ch=0;
			    		for(k=0;k<counttail;k++)
			    		{
			    			if(i==tailX[k] && j==tailY[k])
			    			{
			    				printf("o");
			    				ch=1;
			    				if(gameOver==1)
			    				 goto label2;
							}
						}
						if(ch==0)
			    		printf(" ");
					}
			}
		}
		printf("\n");
	}
	printf("score:%d",score);	
}
void input()
{
	if(kbhit())
	{
		switch(getch())
		{
			case 'a':
				flag=1;//Learn enumerator to use lift and right up and down key
				break;
			case 's':
				flag=2;
				break;
			case 'w':
				flag=3;
				break;
			case 'z':
				flag=4;
				break;
			case 'x':
				gameOver=1;
				break;		
		}
	}	
}
void makeLogic()
{
	int prevX=tailX[0];
	int prevY=tailY[0];
	int prev2X;	
	int prev2Y;
	tailX[0]=x;
	tailY[0]=y;
	int i;
	for(i=1;i<counttail;i++)
	{
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}
	switch(flag)
	{
		case 1:
			y--;
			break;
		case 2:
			y++;
			break;
		case 3:
			x--;
			break;
		case 4:
			x++;
			break;
		default:
			break;
	}
	if (x<0||x>width||y<0||y>height)
	    gameOver=1;
	    for(i=0;i<counttail;i++)
	        {
	 	        if(x==tailX[i] && y==tailY[i])
				    gameOver=1; 
	        } 
    if(x==fruitX && y==fruitY)
	{
		label3:
	    fruitX=rand()%20;
    	if(fruitX==0)
    	goto label3;
    	label4:
	    fruitY=rand()%20;
	    if(fruitY==0)
	    goto label4;
		score+=1;
		counttail++;
	}	
}
void snakeGame()
{
	int n,m;
	char c;
	label5:
	setup();
	    while(!gameOver)
	        {
		        draw();
	            input();
    	        makeLogic();
     	        for(m=0;m<10000;m++)
	                {
		                for(n=0;n<10000;n++)
	             	        {
					        }	
	                }
	        }
    printf("\nPress y for play again");
    fflush(stdin);
    scanf("%c",&c);
    if (c=='y'||c=='Y')
    goto label5;
}
//From here tick tack toe game start
void draw1()
{
	printf("\t\t\t..........................................\n");
	printf("\t\t\t.                                        .\n");
	printf("\t\t\t............TICK TACK TOE GAME............\n");
	printf("\t\t\t.                                        .\n");
	printf("\t\t\t..........................................\n");
	printf("\n\t\t\t\t\t %c : %c : %c",a[0],a[1],a[2]);
	printf("\n\t\t\t\t\t---:---:---");
	printf("\n\t\t\t\t\t %c : %c : %c",a[3],a[4],a[5]);
	printf("\n\t\t\t\t\t---:---:---");
	printf("\n\t\t\t\t\t %c : %c : %c",a[6],a[7],a[8]);	
}
void getinput()
{
	char ch;
	int i;
	printf("\n\t\t\tEnter the position: ");
	scanf("%c",&ch);
	if(k==0)
	{
		for(i=0;i<=8;i++)
	    {
		    if(a[i]==ch)
		    {
			    a[i]='x';
			    k=1;
		    }
	    }
	}
    else
	{
		for(i=0;i<=8;i++)
        {
		    if(a[i]==ch)
		    {
			    a[i]='0';
			    k=0;
		    }
	    }

	}	
}
int gameover()
{
	if(a[0]=='x' &&a[1]=='x' && a[2]=='x')
	return(1);
	else if(a[0]=='x' &&a[3]=='x' && a[6]=='x')
	return(1);
	else if(a[1]=='x' &&a[4]=='x' && a[7]=='x')
	return(1);
	else if(a[2]=='x' &&a[5]=='x' && a[8]=='x')
	return(1);
	else if(a[2]=='x' &&a[4]=='x' && a[6]=='x')
	return(1);
	else if(a[0]=='x' &&a[4]=='x' && a[8]=='x')
	return(1);
	else if(a[3]=='x' &&a[4]=='x' && a[5]=='x')
	return(1);
	else if(a[6]=='x' &&a[7]=='x' && a[8]=='x')
	return(1);
	
	else if(a[0]=='0' &&a[1]=='0' && a[2]=='0')
	return(2);
	else if(a[0]=='0' &&a[3]=='0' && a[6]=='0')
	return(2);
	else if(a[1]=='0' &&a[4]=='0' && a[7]=='0')
	return(2);
	else if(a[2]=='0' &&a[5]=='0' && a[8]=='0')
	return(2);
	else if(a[2]=='0' &&a[4]=='0' && a[6]=='0')
	return(2);
	else if(a[0]=='0' &&a[4]=='0' && a[8]=='0')
	return(2);
	else if(a[3]=='0' &&a[4]=='0' && a[5]=='0')
	return(2);
	else if(a[6]=='0' &&a[7]=='0' && a[8]=='0')
	return(2);
	
	else
    return(3);
}
void final()
{
	int var;
	var=gameover();
	if(var==1)
	{
		printf("\n\t\t\tplayer one won\n");
	    end=0;
	    score++;
	    printf("\t\t\tscore of player one is %d ",score);
	}   
	else if(var==2)
	{
		printf("\n\t\t\tplayer two won\n");
	    end=0;
	    sco++;
	    printf("\t\t\tscore of player two is %d ",sco);
	} 
}
void ticktacktoegame()
{
	char c;
	label:
	system("cls");
	draw1();
	while(end)
	    {
	        getinput();
	        system("cls");
	        draw1();
	        final();   	
	    }
	printf("\n\t\t\tPress y to play again ");
	fflush(stdin);
	scanf("%c",&c);
	if(c=='y'||c=='Y')
	    {
		    a[0]='1';a[1]='2';a[2]='3';a[3]='4';a[4]='5';a[5]='6';a[6]='7';a[7]='8';a[8]='9';
		    k=0;
			end=1;
			goto label;	
		}	
}
//From here casino game start
void playgame()
{
	int i;
	char a[3]={'J','K','Q'};
	int playerChoice;
	srand(time(NULL));
	for(i=1;i<=10;i++)
	{
		int x=rand()%3;
		int y=rand()%3;
		int temp=a[x];
		a[x]=a[y];
		a[y]=temp;
	}
	printf("\t\t\tSuffling is done\n");
	printf("\t\t\tWhat is the position of king ");
	scanf("%d",&playerChoice);
	if(a[playerChoice-1]=='K')
	{
		system("cls");
		cash=cash+2*bettingAmount;
		printf("\t\t\tyou win  \n\t\t\tposition of cards: '%c' '%c' '%c' \n\t\t\tyour current balance is : $%d\n",a[0],a[1],a[2],cash);
		printf("\n\t\t\tPress any key to continue..");
	}
	else
	{
		system("cls");
		cash=cash-bettingAmount;
		printf("\t\t\tyou lose  \n\t\t\tposition of cards: '%c' '%c' '%c' \n\t\t\tyour current balance is : $%d\n",a[0],a[1],a[2],cash);
		printf("\n\t\t\tPress any key to continue..");
	}
	getch();
}
void heading()
{
	printf("\t\t\t.......WELCOME TO MY CASINO........");
	printf("\n\t\t\tTotal cash=$%d\n",cash);
}
void casino()
{
	while(cash>0)
	    {
	        system("cls");
	    	heading();
		    printf("\t\t\tWhat is your betting amount?$ ");
		    scanf("%d",&bettingAmount);
		    if(bettingAmount==0||bettingAmount>cash)
			{
				printf("Insufficent balance\n");
				break;
			}
		    playgame(bettingAmount);
	    }
	    printf("\t\t\tGame over");
	getch();
}
int main()
{
	int x;
	label6:
	printf("\t\t\t...................................\n");
	printf("\t\t\t.                                 .\n");
	printf("\t\t\t.......WELCOME TO GAME STORE.......\n");
	printf("\t\t\t.                                 .\n");
	printf("\t\t\t...................................\n");
	printf("\t\t\tPress 1 for snake game\n");
	printf("\t\t\tPress 2 for rock paper sessior game\n");
	printf("\t\t\tPress 3 for tick tack toe game\n");
	printf("\t\t\tPress 4 for casino game\n");
	printf("\t\t\tEnter your choise ");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
			snakeGame();
			system("cls");
			goto label6;
			break;
		case 2:
			rockPaperGame();
			system("cls");
			goto label6;
			break;
		case 3:
			ticktacktoegame();
			system("cls");
			goto label6;
			break;
		case 4:
			casino();
			system("cls");
			goto label6;
			break;
		default:
			printf("\t\t\tEnter a valid option ");
	}
	return 0;
}
