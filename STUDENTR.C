 #include<stdio.h>
 #include<conio.h>
 #include<graphics.h>
 #include<dos.h>
 #include<stdlib.h>
 #include<string.h>

 void login_window();
 void password_input();
 void draw_screen();
 void main_menu();

 void input();
void display();  
void search();
void searchByRoll();
void searchByName();
void modify();
void del();
void sort();
void sortByRoll();
void sortByName();

struct ADDRESS
   {
    char str[25];
    char im[25];
    char city[15];
    char cou[15];
    char  pin[10];
    };
 
struct student{
char na[30];
char cl[10];
char r1;
char mob[11];
char fna[30];
char mna[30];
char sex[7];
char fees[5];
char date[11];

struct ADDRESS a;
}s;


long si = sizeof(s);

FILE *fp;

 void main()
 {

 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\turboc3\\bgi");

 login_window();
 password_input();
 cleardevice();
 main_menu();

getch();
}


void main_menu(){
int ch;
while(1){
clrscr();
printf("<-----STUDENT RECORD SYSTEM----->\n");
printf("1.Take Addmission\n");
printf("2.Student Info\n");
printf("3.Search\n");
printf("4.Modify\n");
printf("5.Delete\n");
printf("6.Sort\n");
printf("0.exit\n");
printf("Enter your choice: ");
scanf("%d",&ch);

switch(ch){
case 0:
printf("Thankyou for visting!!");
delay(1000);
exit(0);

case 1:
input();
break;

case 2:
display();
break;

case 3:
search();
break;

case 4:
modify();
break;

case 5:
del();
break;

case 6:
sort();
break;

default:
printf("\nInvalid Option\n");
delay(1000);
break;

}
}
}

 void login_window()
 {

  /* rectangle for password input */

    setcolor(3);
    setfillstyle(1,WHITE);
    rectangle(426,288,201,259);
    rectangle(425,287,202,260);
    floodfill(419,262,3);

    /* RECTANGLE FOR LOGO */

    setcolor(WHITE);
    setfillstyle(10,4);
    rectangle(402,142,224,222);
    rectangle(403,141,223,223);
    rectangle(404,140,222,224);
    floodfill( 400,218,WHITE);

    /* draws 1st body */

    setcolor(WHITE);
    setfillstyle(1,2);
    ellipse(270, 190, 0, 360,10, 18);
    ellipse(270, 190, 0, 360,11, 19);
    floodfill(271,191,WHITE);

    /* draws and fills 2nd body  */

    setfillstyle(1,2);
    ellipse(300, 195, 0, 360,10, 18);
    ellipse(300, 195, 0, 360,9, 17);
    floodfill(301,196,WHITE);

    /* draws 3rd body */

      setfillstyle(1,2);
      ellipse(320, 199, 0, 360,8, 12);
      ellipse(320, 199, 0, 360,7, 11);
      floodfill(321,200,WHITE);

    /* draw 4th body */

    setfillstyle(1,2);
    ellipse(340, 190, 0, 360,11, 25);
    ellipse(340, 190, 0, 360,10, 24);
    floodfill(341,191,WHITE);

    /* draws head for 1st body */

    setcolor(WHITE);
    setfillstyle(1,2);
    circle(270,152,9);
    circle(270,152,8);
    floodfill(271,153,WHITE);

   /* draws head for 2nd body */

    setcolor(WHITE);
    setfillstyle(1,2);
    circle(300,160,9);
    circle(300,160,8);
    floodfill(301,161,WHITE);

   /* draws a head for 3rd body */

     setcolor(WHITE);
     setfillstyle(1,2);
     circle(320,180,4);
     circle(320,180,3);
     floodfill(321,181,WHITE);

   /* draws head for 4th body */

    setcolor(WHITE);
    setfillstyle(1,2);
    circle(340,152,9);
    circle(340,152,8);
    floodfill(341,153,WHITE);

    gotoxy(23,16);
    printf("STUDENT RECORD SYSTEM ");

    /* following coad is to draw the circle Enter Button */

    setcolor(WHITE);
    setfillstyle(1,4);
    circle(442,272,12);
    circle(442,272,11);
    circle(442,272,10);
    floodfill(442,272,WHITE);
    outtextxy(435,269,"->");
    setcolor(WHITE);
    circle(442,272,9);
    setbkcolor(0);
    gotoxy(15,15);
    setcolor(WHITE);
    settextstyle(1,0,1);
    outtextxy(512,98,"x");

    /* 510 for right side increaseo or decrease  /
       120 top increase decrease
       130 left increase decrease
       300 bottom increase decrease
       FOLLWING RECTANLGE JUST ABOVE INNERMOST RECTANGLE */

    setcolor(WHITE);
    rectangle(510,120,130,300);

    /* FOLLOWING IS COAD FOR INNER MOST RECTANGLE */

    setcolor(WHITE);
    setfillstyle(1,3);
    rectangle(531,100,112,321);
    floodfill(530,111,WHITE);

    /* FOLLOWING IS THE COAD FOR OUTERMOST WINDOW  */

    setcolor(8);
    setfillstyle(7,8);
    rectangle(532,99,111,322);
    rectangle(533,98,110,323);
    rectangle(534,97,109,324);
    rectangle(535,96,108,325);
    rectangle(536,95,107,326);
    rectangle(537,94,106,327);
    rectangle(538,93,105,328);
    rectangle(539,92,104,329);
    rectangle(540,91,103,328);
    floodfill(0,0,8);

  }

    void password_input()
  {
  int X=206,Y=262;
  char password[10];
  char pass[12]="strecord";
  int i;
  char ch;
  for(i=0;i<12;i++)
  {
  ch=getch();
  password[i]=ch;
  if(ch==13)
  {
    password[i]='\0';
    delay(50);
    for(i=0;i<10;i++)
    {
    sound(99*i);
     /* following coad is to draw the circle Enter Button to give press effect  */
    setcolor(WHITE);
    setfillstyle(1,12);
    circle(442,272,12);
    circle(442,272,11);
    circle(442,272,10);
    floodfill(442,272,WHITE);
delay(19);
    setcolor(WHITE);
    setfillstyle(1,4);
    circle(442,272,12);
    circle(442,272,11);
    circle(442,272,10);
    floodfill(442,272,WHITE);
    nosound();

     }
     delay(1000);

  if(strcmp(pass,password)==0)
  {
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\turboc3\\bgi");
    draw_screen();

    delay(1900); /* This dealy for pause thescreen for sometime.   */
    setcolor(15);
    setfillstyle(1,3);
    rectangle(460,249,140,180);
    rectangle(450,240,148,189);
    floodfill(451,241,15);

      for( i=0;i<10;i++)
    {

    sound(999);
    setcolor(0);
    outtextxy(220,210," ACEESS GRANTED ");
    delay(50);
    setcolor(15);
    outtextxy(220,210," ACEESS GRANTED ");
    nosound();

    }

     delay(1500); /*for pause the screen to sometime to display message. */
     break;

  }
  else
  {
   int gd=DETECT,gm, i;
    initgraph(&gd,&gm,"C:\\turboc3\\bgi");
    draw_screen();

    delay(1400);
    setcolor(15);
    setfillstyle(1,3);
    rectangle(460,249,140,180);
    rectangle(450,240,148,189);
    floodfill(451,241,15);

  /* This for loop is for getting the sound effect */

    for( i=0;i<10;i++)
    {

    sound(999);
    setcolor(0);
    outtextxy(220,210," ACEESS DENIED ");
    delay(99);
    setcolor(15);
    outtextxy(220,210," ACEESS DENIED ");
    nosound();

     }

    delay(2000); /* for pause the screen to sometime to display message. */
    exit(1);

  }

  }

   /* following coad is to check whether the user press backslash or delete
      8 for ascii value of backspace  */

    if(ch==8)
    {
    i--;
    i--;
    X=X-15;
    fflush(stdin);

   /* The following is the restriction for * to print to backward side
      Otherwise the * is printed backward to input box */

    if(X<206)
   {
    X=206;
    }

    setcolor(15);
    settextstyle(2,0,7);
    outtextxy(X,Y,"*");
    X=X-15;
    nosound();

    }

    /* IF YOU PRESS ESC THEN EXITING THE SYSTEM */

    if(ch==27)
    exit(0);

    if(i>10)
    {
     sound(9999);

     }

    sound(800);
    setcolor(0);
    settextstyle(2,0,7);
    outtextxy(X,Y,"*");

    X=X+15;
    delay(100);
    nosound();

  }

  }

   void draw_screen()
   {

   setcolor(15);
   line(0,30,640,30);
   line(0,31,640,31);
   line(0,32,640,32);
   line(0,33,640,33);
   line(0,34,640,34);
   setfillstyle(1,3);
   floodfill(0,0,15);

  /* Bottom Horizontal line */

    setcolor(15);
    line(0,450,640,450);
    line(0,451,640,451);
    line(0,452,640,452);
    line(0,453,640,453);
    line(0,454,640,454);
    setfillstyle(1,3);
    floodfill(0,460,15);

   }

void input(){
fp = fopen("st.txt","ab");  // ab === binary mode opening the file
printf("Enter Name: ");
fflush(stdin);
gets(s.na);

printf("Enter Class: ");
scanf("%s",s.cl);


printf("Enter Roll no:");
scanf("%d",&s.r1);

printf("Enter Father Name: ");
fflush(stdin);
gets(s.fna);

printf("Enter Mother Name: ");
fflush(stdin);
gets(s.mna);

printf("Sex:Female/Male: ");
scanf("%s",s.sex);

printf("Mobile Number: ");
scanf("%s",s.mob);

printf("Enter Fees status: ");
scanf("%s",s.fees);

printf("Enter Date in format DD/MM/YYYY: ");
fflush(stdin);
gets(s.date);

printf("Address[Street]: ");
scanf("%s",s.a.str);

printf("Land Mark: ");
scanf("%s",s.a.im);

printf("City: ");
scanf("%s",s.a.city);

printf("Pin: ");
scanf("%s",s.a.pin);

printf("Country : ");
scanf("%s",s.a.cou);

printf("**************Thankyou*****************\n");


 // reference_of_structure , sizeof(struct) , record_to_one_time, //File_name_open
fwrite(&s, sizeof(s),1,fp);
printf("Record Saved Successfully");
     delay(2000);
fclose(fp);

}


void display(){
int cho;int r1
;
clrscr();
printf("<----Student Info:---->\n");
printf("Enter Roll to search: ");
scanf("%d",&r1);
fp = fopen("st.txt","rb");
while(fread(&s,sizeof(s),1,fp)==1){
if(r1 == s.r1)
{
printf("NAME :: %s\n",s.na);
printf("FATHER NAME:: %s\n",s.fna);
printf("MOTHER NAME:: %s\n",s.mna);
printf("Roll:: %d\t\t",s.r1);
printf("Class:: %s\n",s.cl);
printf("SEX:: %s\t\t",s.sex);
printf("MOBILE NO:: %s\n",s.mob);
printf("FEES STATUS :: %s\n",s.fees);
printf(" **************** ADDRESS *****************\n");

printf("%s\t\t",s.a.str);
printf("%s\n",s.a.im);
printf("%s\t",s.a.city);
printf("-%s\t",s.a.pin);
printf("%s\n",s.a.cou);
break;
}
}
fclose(fp);

printf("Enter 0 to back Main menu: ");
scanf("%d",&cho);
}




void search(){
int ch;
while(1){
clrscr();
printf("<---Student Record System--->\n");
printf("<---Search--->\n");
printf("1.Search By Rollno\n");
printf("2.Search By Name\n");
printf("0.Back to Main Menu\n");
printf("\n\nEnter your choice: \n");
scanf("%d",&ch);

switch(ch){
case 0:
main_menu();
break;

case 1:
searchByRoll();
break;

case 2:
searchByName();
break;

default:
printf("Invalid Choice");
break;
}
getch();
}
}

void searchByRoll(){
int r1;
printf("Enter Roll to search: ");
scanf("%d",&r1);
printf("%-30s %-20s %-10s %s\n","Name","Class","Roll","Date");
fp = fopen("st.txt","rb");

while(fread(&s,sizeof(s),1,fp)==1){
if(r1 == s.r1){
printf("%-30s %-20s %-10d %s\n",s.na,s.cl,s.r1,s.date);
break;
}
}
fclose(fp);
}

void searchByName(){
char na[30];
int f=0;
printf("Enter name to search: ");
fflush(stdin);
gets(na);
printf("%-30s %-20s %-10s %s\n","Name","Class","Roll","Date");
fp = fopen("st.txt","rb");

while(fread(&s,sizeof(s),1,fp)==1){
if(strcmpi(na,s.na)==0){
f =1;
printf("%-30s %-20s %-10d %s\n",s.na,s.cl,s.r1,s.date);
break;
}
}
fclose(fp);

if(f == 0)
printf("Record not found");
else
printf("Record found successfully");
}


void modify(){
int r1, f=0;
printf("Enter Roll to Modify: ");
scanf("%d",&r1);
fp = fopen("st.txt","rb+");//rb+ ---> read and record both will happen

while(fread(&s,sizeof(s),1,fp)==1){
if(r1 == s.r1){
f=1;
printf("Enter New Name: ");
fflush(stdin);
gets(s.na);
printf("Enter Class:");
scanf("%s",s.cl);
printf("Enter New Roll: ");
scanf("%d",&s.r1);
fseek(fp,-si,1);
fwrite(&s,sizeof(s),1,fp);
fclose(fp);
break;
}//if

}//while
if(f == 0){
printf("Record not found");
delay(2000);
}
else{
printf("Record found successfully");
delay(2000);
}
}

void del(){
int r1, f=0;
printf("Enter roll to delete: ");
scanf("%d",&r1);

FILE *ft;
fp = fopen("st.txt","rb");
ft = fopen("temp.txt","ab");

while(fread(&s,sizeof(s),1,fp)==1){
if(r1 == s.r1){
f=1;
}else{
fwrite(&s,sizeof(s),1,ft);
}
}
fclose(fp);
fclose(ft);
remove("st.txt");
rename("temp.txt","st.txt");

if(f==0){
printf("Record NOt found..");
delay(2000); }
else{
printf("Record Deleted successfully..");
delay(2000); }
}

void sort(){
int ch;
while(1){
clrscr();
printf("<---Student Record System--->\n");
printf("<---Search--->\n");
printf("1.Sort By Rollno\n");
printf("2.Sort By Name\n");
printf("0.Back to Main Menu\n");
printf("\n\nEnter your choice: ");
scanf("%d",&ch);

switch(ch){
case 0:
main_menu();
break;

case 1:
sortByRoll();
break;

case 2:
sortByName();
break;

default:
printf("Invalid Choice");

}
getch();
}
}

void sortByRoll(){
clrscr();
int c=0,i,j;
struct student s1[50] ,t;
printf("<---School Record--->\n");
printf("<---Sort By Roll--->\n");
fp = fopen("st.txt","rb");
while(fread(&s,sizeof(s),1,fp)==1)
s1[c++] = s;

for(i=0; i<c-1; i++){
for(j=i+1; j<c; j++){
if(s1[i].r1>s1[j].r1){
t = s1[i];
s1[i] = s1[j];
s1[j] = t;
}
}
}
printf("%-30s %-20s %-10s %s\n","Name","Class","Roll","Date");

for(i=0; i<c; i++)
printf("%-30s %-20s %-10d %s\n",s1[i].na,s1[i].cl,s1[i].r1,s1[i].date);

}

void sortByName(){
clrscr();
int c=0,i,j;
struct student s1[50] ,t;
printf("<---School Management--->\n");
printf("<---Sort By Roll--->\n");
fp = fopen("st.txt","rb");
while(fread(&s,sizeof(s),1,fp)==1)
s1[c++] = s;

for(i=0; i<c-1; i++){
for(j=i+1; j<c; j++){
if(strcmpi(s1[i].na, s1[j].na)>1){
t = s1[i];
s1[i] = s1[j];
s1[j] = t;
}
}
}
printf("%-30s %-20s %-10s %s\n","Name","Class","Roll","Date");

for(i=0; i<c; i++)
printf("%-30s %-20s %-10d %s\n",s1[i].na,s1[i].cl,s1[i].r1,s1[i].date);

}