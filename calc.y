
%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
extern FILE* yyin;
FILE* fp;
struct node{
	char *data;
	struct node* next;
};
typedef struct node node;
node* getnode(char *data,node* next)
{
	node *p=(node*)malloc(sizeof(node));
	char *new_string = (char *)malloc(strlen(data) + 1); 
	strcpy(new_string,data);
	p->data=new_string;
	p->next=next;
return p;
}
void append(char *s,node* t)
{
	while(t->next != NULL)
	{
		t = t->next;
	}
	node *p=getnode(s,NULL);
	t->next = p;
	t = t -> next;
}
void newJump(int jump,node* t)
{
	while(t->next != NULL)
	{
		t = t->next;
	}
	char temp[100];
	sprintf(temp,".L%d",jump);
	node *p=getnode(temp,NULL);
	t->next = p;
	t = t -> next;
}
node *code;
node *data;
node *jump;
int answer = 0;
int countdata = 0;
int top =0;
int size =0;
int last_count_byte =0;
int num =0;
char a = '0';
bool checkJump = false;
int jumppoint = 1;
int count_byte = 0;
bool checkString = false;
int  reg[27] ; //เก็บค่า int ของตัวแปร
char regChar[27]; //เก็บค่า char ของตัวแปร
char *regString[27];//เก็บค่า string ของตัวแปร
float regFloat[100];
int regByte[27];
int type[100] ;//เก็บค่า type ของตัวแปร
bool checkBool = false;
bool checkRegEqual(char a,char b);
void yyerror(char* s);
int getAnswer();
int getRegValue(char c);
int LoadValue(char c,int number);
void LoadValueChar(char c,char assgin);
void LoadValueString(char c,char *s);
int LoadReg(char c1,char c2);
int showRegister(char c);
int LoadValueNum(char c,int number);
void ChangeString(char *s);
%}

%union {
	char* s;
	int ival;
	float fval;
	char id;
}

%token<ival> T_INT IF For
%token<fval> T_FLOAT
%token<ival> identifier
%token<id> Answer 
%token<s> String
%token<id> Show Load Push Pop Top Size Char ShowHex
%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE T_LEFT T_RIGHT IS  INT FLOAT  Str OPENLOOP ENDLOOP
%token T_NEWLINE T_QUIT Single_Quotes Double_Quotes  MoreThan MoreThan_EQUAL LessThan LessThan_EQUAL ELSE
%left AND OR NOT EQUAL Not_EQUAL
%left T_PLUS T_MINUS
%left T_MULTIPLY T_DIVIDE T_MOD
%right T_RAISED

%type<ival> expression
%type<fval> mixed_expression
%type<ival> assginValue
%type<ival> Condition
%type<ival> Loop

%start calculation

%%

calculation: 
	   | calculation line
;

line: T_NEWLINE
    | Show mixed_expression 	 								{ printf("%f\n", $2);}
    | Show expression 											{ printf("%i\n",$2);  //แสดงค่า int
		
			char temp[100];
			sprintf(temp,".LC%d",countdata);
			append(temp,data);
			append("\t.string %d",data);
			sprintf(temp,"\tmov     esi, %d",$2);
			append(temp,code);
			sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
			append(temp,code);
			append("\tcall    printf",code);
			countdata = countdata +1;

	
	} 
	| ShowHex expression 										{ printf("%xh\n",$2); //แสดงค่า int เลขฐาน 16
	
	
			char temp[100];
			sprintf(temp,".LC%d",countdata);
			append(temp,data);
			append("\t.string %x",data);
			sprintf(temp,"\tmov     esi, %d",$2);
			append(temp,code);
			sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
			append(temp,code);
			append("\tcall    printf",code);
			countdata = countdata +1;

	}
	| ShowHex identifier										{ if(type[$2] == 1){printf("%xh\n",reg[$2]);//แสดงค่า ตัวแปร int เลขฐาน 16
			char temp[100];
			sprintf(temp,".LC%d",countdata);
			append(temp,data);
			append("\t.string %x",data);
			sprintf(temp,"\tmov     eax, DWORD PTR [rbp-%d]",regByte[$2]);
			append(temp,code);
			append("\tmov     esi, eax",code);
			sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
			append(temp,code);
			append("\tmov     eax, 0",code);
			append("\tcall    printf",code);
			}
			else{
				printf("ERROR Type is not match");
			}

	}
    | T_QUIT 														{ printf("bye!\n"); exit(0);}
	| Show identifier 												{ showRegister($2);} //แสดงค่าในตัวแปรที่เก็บไว้
	| identifier IS  identifier  									{ LoadReg($1,$3);} //ใส่ค่าให้กับตัวแปร ผ่านตัวแปร
	| Show Double_Quotes String Double_Quotes 						{ ChangeString($3); if(checkString == false){
			
				char temp[100];										//ปริ้นstring
				sprintf(temp,".LC%d",countdata);
				append(temp,data);
				sprintf(temp,"\t.string %s",$3);
				append(temp,data);
				sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
				append(temp,code);
				append("\tcall    printf",code);
				countdata = countdata +1;

		}
	}
	| Show Single_Quotes Char Single_Quotes 				{ printf("%c\n",$3);
			char temp[100];											//ปริ้นChar
			sprintf(temp,"\tmov     edi,%d",$3);
			append(temp,code);
			append("\tcall    putchar",code);

	}
	| Condition
	| Loop
	| identifier IS expression				     { type[$1] = 1;LoadValue($1,$3); //ใส่ค่า int ให้กับตัวแปร 
			if(count_byte == 0) 
			{
				regByte[$1] = 4;
				char temp[100];
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d], %d",regByte[$1],$3);
				append(temp,code);
				count_byte = 4;
			}
			else
			{
				regByte[$1] = ((count_byte%4)+2)*4;
				char temp[100];
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d], %d",regByte[$1],$3);
				append(temp,code);
				count_byte = regByte[$1];
			}
	}
	| identifier IS Single_Quotes Char Single_Quotes 	 {type[$1] = 2;LoadValueChar($1,$4); //ใส่ค่า char ให้กับตัวแปร
			if(count_byte == 0)
			{
				regByte[$1] = 1;
				char temp[100];
				sprintf(temp,"\tmov     BYTE PTR [rbp-%d], %d",regByte[$1],$4);
				append(temp,code);
				count_byte = 1;
			}
			else
			{
				regByte[$1] = count_byte+1;
				char temp[100];
				sprintf(temp,"\tmov     BYTE PTR [rbp-%d], %d",regByte[$1],$4);
				append(temp,code);
				count_byte  = regByte[$1];
			}	
	}
	| identifier IS Double_Quotes String Double_Quotes  {type[$1] = 3;char* s = (char*)malloc(200); s=$4;LoadValueString($1,s); //ใส่ค่า string ให้กับตัวแปร
			if(count_byte == 0)
			{
				regByte[$1] = 8;
				char temp[100];
				sprintf(temp,"\tmov     BYTE PTR [rbp-%d], %d",regByte[$1],$4);
				append(temp,code);
				count_byte = 1;
			}
			else
			{
				regByte[$1] = (abs(count_byte-8)+1)*8;
				char temp[100];
				sprintf(temp,"\tmov     BYTE PTR [rbp-%d], %d",regByte[$1],$4);
				append(temp,code);
				count_byte  = regByte[$1];
			}	
	}	

	| identifier IS assginValue 							
		{ 	
			type[$1] = 1;
			regByte[$1] = num;
			reg[$1] = $3;

		}
	  
	
;

mixed_expression: T_FLOAT                 			 { $$ = $1; }
	  | mixed_expression T_PLUS mixed_expression	 { $$ = $1 + $3; }
	  | mixed_expression T_MINUS mixed_expression	 { $$ = $1 - $3; }
	  | mixed_expression T_MULTIPLY mixed_expression { $$ = $1 * $3; }
	  | mixed_expression T_DIVIDE mixed_expression	 { $$ = $1 / $3; }
	  | mixed_expression T_RAISED mixed_expression   { $$ = pow ($1, $3);}
	  | mixed_expression T_MOD	mixed_expression	 { $$ = fmod($1,$3);}
	  | T_LEFT mixed_expression T_RIGHT		 	 	 { $$ = $2; }
	  | expression T_RAISED mixed_expression         { $$ = pow ($1, $3);}
	  | expression T_PLUS mixed_expression	 	     { $$ = $1 + $3; }
	  | expression T_MINUS mixed_expression	 	     { $$ = $1 - $3; }
	  | expression T_MULTIPLY mixed_expression 	     { $$ = $1 * $3; }
	  | expression T_DIVIDE mixed_expression	    { $$ = $1 / $3; }
	  | expression T_MOD mixed_expression		    { $$ = fmod($1,$3);}
	  | mixed_expression T_PLUS expression	 	    { $$ = $1 + $3; }
	  | mixed_expression T_MINUS expression	 	    { $$ = $1 - $3; }
	  | mixed_expression T_MULTIPLY expression 	   { $$ = $1 * $3; }
	  | mixed_expression T_DIVIDE expression	   { $$ = $1 / $3; }
	  | mixed_expression T_RAISED expression       { $$ = pow ($1, $3);}
	  | mixed_expression T_MOD expression		   { $$ = fmod($1,$3);}
	  | expression T_DIVIDE expression		 	   { $$ = $1 / (float)$3; }
;




assginValue: identifier { if(type[$1] == 1){$$ = getRegValue($1);last_count_byte = regByte[$1];}else{printf("ERROR Not math type\n");} }
	  | assginValue T_PLUS assginValue  	{ $$ = $1 + $3;
	  			 num = ((count_byte%4)+2)*4;
				char temp[100];
				append("\tmov     eax, DWORD PTR [rbp]",code);
				append("\tmov     edx, DWORD PTR [rbp]",code);
				append("\tlea     eax, [rdx+rax]",code);
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d]",num);
				append(temp,code);
				count_byte = num;
	  }
	  | assginValue T_PLUS expression		{ $$ = $1 + $3;
				
				 num = ((count_byte%4)+2)*4;
				char temp[100];
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d]",last_count_byte);
				append(temp,code);
				sprintf(temp,"\tadd     eax,%d",$3);
				append(temp,code);
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d], eax",num);
				append(temp,code);
				count_byte = num;
	  
	  }
	  | assginValue T_MINUS assginValue  	{ $$ = $1 - $3;
	  			num = ((count_byte%4)+2)*4;
				char temp[100];
	  			append("\tmov     eax, DWORD PTR [rbp]",code);
				append("\tmov     edx, DWORD PTR [rbp]",code);
				append("\tmov     ecx, edx",code);
				append("\tsub     ecx, eax",code);
				append("\tmov     eax, ecx",code);
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d], eax",num);
				append(temp,code);
				count_byte = num;
	  }
	  | assginValue T_MINUS expression { $$ = $1-$3;
	  			num = ((count_byte%4)+2)*4;
				char temp[100];
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d]",last_count_byte);
				append(temp,code);
				sprintf(temp,"\tsub     eax,%d",$3);
				append(temp,code);
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d], eax",num);
				append(temp,code);
				count_byte = num;
	  }
	  | assginValue T_MULTIPLY assginValue  { $$ = $1 * $3;
	  			num = ((count_byte%4)+2)*4;
				char temp[100];
				append("\tmov     eax, DWORD PTR [rbp]",code);
				append("\timul    eax, DWORD PTR [rbp]",code);								
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d],eax",num);
				append(temp,code);
				count_byte = num;
	  }
	  | assginValue T_MULTIPLY expression  { $$ = $1 * $3;
	  			num = ((count_byte%4)+2)*4;
				char temp[100];
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d]",last_count_byte);
				append(temp,code);
				append("\tmov     eax, edx",code);
				append("\tsal     eax, 2",code);
				append("\tadd     eax, edx",code);
				append("\tadd     eax, eax",code);
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d], eax",num);
				append(temp,code);
				count_byte = num;
	  }
	  | assginValue T_DIVIDE assginValue    { $$ = $1 / $3;
	  			num = ((count_byte%4)+2)*4;
				char temp[100];
				append("\tmov     eax, DWORD PTR [rbp]",code);
				append("\tmov     edx, eax",code);
				append("\t sar     edx, 31",code);
				append("\tidiv    eax, DWORD PTR [rbp]",code);								
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d],eax",num);
				append(temp,code);
				count_byte = num;
	  
	  }
	  | assginValue T_DIVIDE expression		{ $$ = $1/$3;
	  			num = ((count_byte%4)+2)*4;
				char temp[100];
				sprintf(temp,"\tmov     eax,DWORD PTR [rbp-%d]",last_count_byte);
				append(temp,code);
				append("\tmov     edx, eax",code);
				append("\tshr     edx, 31",code);
				append("\tlea      eax, [rdx+rax]",code);
				append("\tsar      eax",code);
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d], eax",num);
				append(temp,code);
				count_byte = num;
	  
	  }
	  | assginValue T_MOD assginValue    	{ $$ = fmod($1 ,$3);
				num = ((count_byte%4)+2)*4;
				char temp[100];
				append("\tmov     eax, DWORD PTR [rbp]",code);
				append("\tmov     edx, eax",code);
				append("\t sar     edx, 31",code);
				append("\tidiv    eax, DWORD PTR [rbp]",code);								
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d],eax",num);
				append(temp,code);
				count_byte = num;
	  }
	  | assginValue T_MOD expression    	{ $$ = fmod($1 ,$3);
				num = ((count_byte%4)+2)*4;
				char temp[100];
				sprintf(temp,"\tmov     eax,DWORD PTR [rbp-%d]",last_count_byte);
				append(temp,code);
				append("\tmov     edx, eax",code);
				append("\tsar     edx, 31",code);
				append("\tshr     edx, 31",code);
				append("\tadd     eax, edx",code);
				append("\tand     eax, 1",code);
				append("\tsub     eax, edx",code);
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d], eax",num);
				append(temp,code);
				count_byte = num;
	  }
	  | assginValue T_RAISED assginValue    { $$ = pow($1 ,$3);

	  			num = ((count_byte%4)+2)*4;
				char temp[100];
				append("\tmov     eax, DWORD PTR [rbp]",code);
				append("\tmov     edx, DWORD PTR [rbp]",code);
				append("\txor     eax, edx",code);								
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d],eax",num);
				append(temp,code);
				count_byte = num;
	  }
	  | T_LEFT assginValue T_RIGHT		 	{ $$ = $2; }
	 
;


expression: T_INT						{ $$ = $1; }
	  | expression T_PLUS expression	{ $$ = $1 + $3; }
	  | expression T_MINUS expression	{ $$ = $1 - $3; }
	  | expression T_MULTIPLY expression{ $$ = $1 * $3; }
	  | T_LEFT expression T_RIGHT		{ $$ = $2; }
	  | expression T_RAISED expression  { $$ = pow ($1, $3); }
	  | expression T_MOD expression     { $$ = fmod($1,$3);}
	  | T_MINUS expression 			    { $$ = -$2;}
	  | expression AND expression		{ $$ = $1 && $3;}
	  | expression OR expression 		{ $$ = $1 || $3;}
	  | NOT expression					{ $$ = !$2;}
;

Condition: IF							{ $$ = $1;} //การทำ statement เงื่ื่อนไข
	  | IF Condition_stage T_NEWLINE OPENLOOP T_NEWLINE Show Double_Quotes String Double_Quotes T_NEWLINE  ENDLOOP 										 	
	  	{if(checkBool){ printf("%s\n",$8); }
		  	
				char temp[100];
				sprintf(temp,".LC%d",countdata);
				append(temp,data);
				sprintf(temp,"\t.string %s",$8);
				append(temp,data);
				sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
				append(temp,code);
				append("\tcall    printf",code);
				jumppoint = jumppoint +1;
				sprintf(temp,".L%d:",jumppoint);
				append(temp,code);
				countdata = countdata +1;
		  }  
	   | IF Condition_stage T_NEWLINE OPENLOOP T_NEWLINE Show Double_Quotes String Double_Quotes T_NEWLINE  ENDLOOP ELSE T_NEWLINE OPENLOOP T_NEWLINE Show Double_Quotes String Double_Quotes T_NEWLINE ENDLOOP										 	
	  	{if(checkBool){ printf("%s\n",$8);}
		  	
				char temp[100];
				sprintf(temp,".LC%d",countdata);
				append(temp,data);
				sprintf(temp,"\t.string %s",$8);
				append(temp,data);
				sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
				append(temp,code);
				append("\tcall    printf",code);
				jumppoint = jumppoint+2;
				sprintf(temp,"\tjmp     .L%d",jumppoint);
				append(temp,code);
				countdata = countdata +1;
				sprintf(temp,".LC%d",countdata);
				append(temp,data);
				sprintf(temp,"\t.string %s",$18);
				append(temp,data);
				sprintf(temp,".L%d",jumppoint-1);
				append(temp,code);
				sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
				append(temp,code);
				append("\tmov     eax, 0",code);
				append("\tcall    printf",code);
				newJump(jumppoint,code);
				countdata = countdata +1;

		  }  	  
	  | IF Condition_stage T_NEWLINE OPENLOOP T_NEWLINE identifier IS expression  T_NEWLINE ENDLOOP 								{if(checkBool){type[$6] = 1;LoadValue($6,$8);}}
	  | IF Condition_stage T_NEWLINE OPENLOOP T_NEWLINE identifier IS Char  T_NEWLINE ENDLOOP 										{if(checkBool){type[$6] = 2;LoadValueChar($6,$8);}}
	  | IF Condition_stage T_NEWLINE OPENLOOP T_NEWLINE identifier IS String  T_NEWLINE ENDLOOP 									{if(checkBool){type[$6] = 3;char* s = (char*)malloc(100); s=$8;  LoadValueString($6,s);}}
	  | IF Condition_stage T_NEWLINE OPENLOOP T_NEWLINE Show identifier T_NEWLINE ENDLOOP 											{if(checkBool){printf("%d\n",reg[$7]);}}
;

Loop:For identifier LessThan expression expression T_NEWLINE  OPENLOOP  T_NEWLINE Show Double_Quotes String Double_Quotes T_NEWLINE  ENDLOOP							     {int start = reg[$2];if(type[$2]==1){for(start;start<$4;start=start+$5){printf("%s\n",$11);}
										//Loopเดียว
				char temp[100];
				sprintf(temp,"\tmov     DWORD PTR [rbp-%d],%d",regByte[$2],reg[$2]);
				append(temp,code);
				sprintf(temp,"\tjmp     .L%d",jumppoint+1);
				append(temp,code);
				sprintf(temp,".L%d:",jumppoint+2);
				append(temp,code);
				sprintf(temp,".LC%d",countdata);
				append(temp,data);
				sprintf(temp,"\t.string %s",$11);
				append(temp,data);
				sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
				append(temp,code);
				append("\tcall    printf",code);
				countdata = countdata +1;
				sprintf(temp,"\tadd     DWORD PTR [rbp-%d],%d",regByte[$2],$5);
				append(temp,code);
				sprintf(temp,".L%d:",jumppoint+1);
				append(temp,code);
				sprintf(temp,"cmp     DWORD PTR [rbp-%d], %d",regByte[$2],$4-1);
				append(temp,code);
				append("\tsetle   al",code);
				append("\ttest    al, al",code);
				sprintf(temp,"\tjne     .L%d",jumppoint+2);
				append(temp,code);
				jumppoint = jumppoint +3;
				newJump(jumppoint,code);
				count_byte = ((count_byte%4)+2)*4;				
				}
				else{
					printf("ERROR Type is not match in Int \n");
				}


	}
	|For identifier LessThan expression expression T_NEWLINE  For identifier LessThan expression expression  T_NEWLINE  Show Double_Quotes String Double_Quotes T_NEWLINE Show  Double_Quotes String Double_Quotes T_NEWLINE 
			{	if( ( type[$2] == 1) && (type[$8] == 1) ){ //Loop ซ้อน Loop
				int start = reg[$2];
				int start2 = reg[$8];
				for(start;start<$4;start=start+$5)
				{
					
						for(start2;start2<$10;start2=start2+$11)
						{
							printf("%s\n",$15);
						}
						start2 =0;

						printf("%s\n",$20);
				}
				char temp[100];
									sprintf(temp,"\tmov     DWORD PTR [rbp-%d],%d",regByte[$2],reg[$2]);
									append(temp,code);
									sprintf(temp,"\tjmp     .L%d",jumppoint+1);
									append(temp,code);
									sprintf(temp,".L%d:",jumppoint+4);
									append(temp,code);
									sprintf(temp,".LBB%d:",jumppoint+4);
									append(temp,code);
									sprintf(temp,"\tmov     DWORD PTR [rbp-%d],%d",regByte[$8],reg[$8]);
									append(temp,code);
									sprintf(temp,"\tjmp     .L%d",jumppoint+2);
									append(temp,code);
									sprintf(temp,".L%d:",jumppoint+3);
									append(temp,code);
									sprintf(temp,".LC%d",countdata);
									append(temp,data);
									sprintf(temp,"\t.string %s",$20);
									append(temp,data);
									sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
									append(temp,code);
									append("mov     eax, 0",code);
									append("\tcall    printf",code);
									countdata = countdata +1;
									sprintf(temp,"\tadd     DWORD PTR [rbp-%d], %d",regByte[$8],$11);
									append(temp,code);
									sprintf(temp,".L%d:",jumppoint+2);
									append(temp,code);
									sprintf(temp,"\tcmp     DWORD PTR [rbp-%d], %d",regByte[$8],$10-1);
									append(temp,code);
									append("\tsetle   al",code);
									append("\ttest    al, al",code);
									sprintf(temp,"\tjne     .L%d",jumppoint+3);
									append(temp,code);
									sprintf(temp,".LBB%d:",jumppoint+4);
									append(temp,code);
									sprintf(temp,".LC%d",countdata);
									append(temp,data);
									sprintf(temp,"\t.string %s",$15);
									append(temp,data);
									sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
									append(temp,code);
									append("\tmov     eax, 0",code);
									append("\tcall    printf",code);
									countdata = countdata +1;
									sprintf(temp,".LBE%d:",jumppoint+3);
									append(temp,code);
									sprintf(temp,"\tadd     DWORD PTR [rbp-%d], %d",regByte[$2],$5);
									append(temp,code);
									sprintf(temp,".L%d:",jumppoint+1);
									append(temp,code);
									sprintf(temp,"\tcmp     DWORD PTR [rbp-%d], %d",regByte[$2],$4-1);
									append(temp,code);
									append("\tsetle   al",code);
									append("\ttest    al, al",code);
									sprintf(temp,"\tjne     .L%d",jumppoint+4);
									jumppoint = jumppoint+6;
									newJump(jumppoint,code);
			}
			else{
					printf("ERROR Type is not match in Int \n");
			}
				
			}
		| For identifier LessThan expression expression T_NEWLINE OPENLOOP  T_NEWLINE Condition T_NEWLINE ENDLOOP {  int start = reg[$2];if(type[$2]==1){
		 for(start;start<$4;start=start+$5)
		{
			if(start%2!=0)
			{
				printf("%d\n",start);
			}
			
			}
		}
		}
;


Condition_stage: expression EQUAL expression				{if($1 == $3){ checkBool = true;}}  //เป็นการเช๊คเงื่อนไขว่า true false
	  | expression Not_EQUAL expression						{if($1 != $3){ checkBool = true;}}
	  | expression MoreThan expression						{if($1 > $3){ checkBool = true;}}
	  | expression MoreThan_EQUAL expression				{if($1 >= $3){ checkBool = true;}}
	  | expression LessThan expression						{if($1 < $3){ checkBool = true;}}
	  | identifier EQUAL expression							
	  	{if(type[$1] == 1){if(reg[$1] == $3){ checkBool = true;}
		  		char temp[100];
				sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[$1],$3);
				append(temp,code);
				sprintf(temp,"\tjne     .L%d",jumppoint+1);
				append(temp,code);
		} else{printf("ERROR Not math type\n");}}
	  | identifier Not_EQUAL expression						
	  {if(type[$1] == 1){if(reg[$1] != $3){ checkBool = true;}
	  			char temp[100];
				sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[$1],$3);
				append(temp,code);
				sprintf(temp,"\tjne     .L%d",jumppoint+1);
				append(temp,code);
	  }else{printf("ERROR Not math type\n");}}
	  | identifier MoreThan expression						
	  {if(type[$1] == 1){if(reg[$1] > $3){ checkBool = true;}
	  			char temp[100];
				sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[$1],$3);
				append(temp,code);
				sprintf(temp,"\tjne     .L%d",jumppoint+1);
				append(temp,code);
	  }else{printf("ERROR Not math type\n");}}
	  | identifier MoreThan_EQUAL expression				{if(type[$1] == 1){if(reg[$1] >= $3){ checkBool = true;}
	  			char temp[100];
				sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[$1],$3-1);
				append(temp,code);
				sprintf(temp,"\tjne     .L%d",jumppoint+1);
				append(temp,code);
	  }else{printf("ERROR Not math type\n");}}
	  | identifier LessThan expression						{if(type[$1] == 1){if(reg[$1] < $3){ checkBool = true;}
	  			char temp[100];
				sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[$1],$3-1);
				append(temp,code);
				sprintf(temp,"\tjne     .L%d",jumppoint+1);
				append(temp,code);
	  }else{printf("ERROR Not math type\n");}}
	| identifier LessThan_EQUAL expression						{if(type[$1] == 1){if(reg[$1] <= $3){ checkBool = true;}
	  			char temp[100];
				sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[$1],$3);
				append(temp,code);
				sprintf(temp,"\tjne     .L%d",jumppoint+1);
				append(temp,code);
	  }else{printf("ERROR Not math type\n");}}
	  | identifier EQUAL identifier						{if(type[$1] == type[$3])
	  {if(checkRegEqual($1,$3)){ checkBool = true;
	  			char temp[100];
				sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[$1]);
				append(temp,code);
				sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[$3]);
				append(temp,code);
				sprintf(temp,"\tjne     .L%d",jumppoint+1);
				append(temp,code);

	  }

	  }else{printf("ERROR Not math type\n");}}
	  | identifier Not_EQUAL identifier						
	  	{if(type[$1] == type[$3])
		  {
			  if(checkRegEqual($1,$3))
		  		 checkBool = false;
				   else
				   checkBool =true;
				   char temp[100];
					sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[$1]);
					append(temp,code);
					sprintf(temp,"\tcmp     DWORD PTR [rbp-%d],%d",regByte[$3]);
					append(temp,code);
					append("\tje     .L2",code);

			  }
			  else
			  {	printf("ERROR Not math type\n");
			  	}
			  }
	  | identifier EQUAL Char								{if(type[$1] == 2){if(regChar[$1] == $3){ checkBool = true;}}else{printf("ERROR Not math type\n");}}
	  | identifier Not_EQUAL Char							{if(type[$1] == 2){if(regChar[$1] != $3){ checkBool = true;}}else{printf("ERROR Not math type\n");}}
	  | identifier EQUAL String								{if(type[$1] == 3){if(!strcmp(regString[$1], $3)){ checkBool = true;}}else{printf("ERROR Not math type\n");}}
	  | identifier Not_EQUAL String							{if(type[$1] == 3){if(strcmp(regString[$1], $3)){ checkBool = false;}else{ checkBool = true;}}else{printf("ERROR Not math type\n");}}
	  | assginValue Not_EQUAL expression					{if($1!=$3){ checkBool = true;}else{ checkBool = false;}}
	  ;
	  
%%
int updateAnswer(int number)
{
	answer = number;
}

int LoadValue(char c,int number)
{	
	
	reg[c] = number;
	
	return 0;
}

void LoadValueChar(char c,char assgin)
{
	regChar[c] = assgin;

}

void LoadValueString(char c,char *s)
{
	regString[c] = s;
}



int LoadReg(char c1,char c2) //นำค่าตัวแปรหนึ่งใส่อีกตัวแปรหนึ่ง
{
	type[c1] == type[c2];
	if(type[c1] == 1)
	{
		reg[c1] = reg[c2];
		char temp[100];
		sprintf(temp,"\tmov     eax, DWORD PTR [rbp-%d]",regByte[c2]);
		append(temp,code);
		regByte[c1] = ((count_byte%4)+2)*4;
		sprintf(temp,"\tmov     DWORD PTR [rbp-%d], eax",regByte[c1]);
	    append(temp,code);
		count_byte = regByte[c1];

	}
	else if(type[c1] == 2)
	{
		regChar[c1] = regChar[c2];
		char temp[100];
		sprintf(temp,"\tmov     eax, BYTE PTR [rbp-%d]",regByte[c2]);
		append(temp,code);
		regByte[c1] = count_byte+1;
		sprintf(temp,"\tmov     BYTE PTR [rbp-%d], eax",regByte[c1]);
	    append(temp,code);
		count_byte = regByte[c1];

	}
	else if(type[c1] == 3)
	{
		regString[c2] = regString[c1];
		char temp[100];
		sprintf(temp,"\tmov     rax, QWORD PTR [rbp-%d]",regByte[c2]);
		append(temp,code);
		regByte[c1] = (abs(count_byte-8)+1)*8;
		sprintf(temp,"\tmov     QWORD PTR [rbp-%d], eax",regByte[c1]);
	    append(temp,code);
		count_byte = regByte[c1];
	}

	return 0;
}





bool checkRegEqual(char a,char b)
{
	if(type[a] == 1)
	{
		if(reg[a] == reg[b])
			return true;
	}
	if(type[a] == 2)
	{
		if(regChar[a] == regChar[b])
			return true;
	}
	if(type[a] == 3)
	{
		if(strcmp(regString[a],regString[b]))
			return false;
			else
			return true;
	}
	return false;

}


int getRegValue(char c)
{
	if(type[c] == 1)
	{
		return reg[c];
	}

	return 0;

}

int showRegister(char c)
{
	if(type[c] == 1)
	{
		printf(" %d\n",reg[c]);
		
			char temp[100];
			sprintf(temp,".LC%d",countdata);
			append(temp,data);
			append("\t.string %d",data);
			sprintf(temp,"\tmov     eax, DWORD PTR [rbp-%d]",regByte[c]);
			append(temp,code);
			append("\tmov     esi, eax",code);
			sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
			append(temp,code);
			append("\tmov     eax, 0",code);
			append("\tcall    printf",code);
	

	}
	else if(type[c] == 2)
	{
		printf("= %c\n",regChar[c]);
		char temp[100];
		sprintf(temp,"\tmovsx     eax,BYTE PTR [rbp-%d], %d",regByte[c]);
		append(temp,code);
		append("\tmov     edi, eax",code);
		append("\tcall    putchar",code);
	}
	else if(type[c] == 3)
	{
			
	
			printf("%s\n",regString[c]);
			char temp[100];
			sprintf(temp,".LC%s",countdata);
			append(temp,data);
			append("\t.string %d",data);
			sprintf(temp,"\tmov     eax, QWORD PTR [rbp-%d]",regByte[c]);
			append(temp,code);
			append("\tmov    	rsi, rax",code);
			sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
			append(temp,code);
			append("\tmov     eax, 0",code);
			append("\tcall    printf",code);

	}
	else if(type[c] == 4)
	{
		printf("= %f\n",regFloat[c]);
	}
	else 
	printf("Error the register is NULL\n");
	

	return 0;
}
void ChangeString(char *s)
{
	int count = strlen(s);
	int i = 0;
	while(i<= count-1)
	{
		if((s[i] == '$') && (s[i+1] == 'n' ))
		{
			checkString = true;
			s[i] = ' ';
			s[i+1] = '\n';
		}
		i++;
	}
	printf("%s\n",s);
	if(checkString){
					int i = 0;
				while(i<= count-1)
				{
					if((s[i] == '$') && (s[i+1] == 'n' )) //ในกรณีที่อ่านเจอ $n ซึ่งเป็นการขึ้นบรรทัดใหม่
					{
						s[i] = ' ';
						s[i+1] = ' ';
					}
					i++;
				}
		
			char temp[100];
			sprintf(temp,".LC%d",countdata);
			append(temp,data);
			sprintf(temp,"\t.string %s",s);
			append(temp,data);
			sprintf(temp,"\tmov     edi, OFFSET FLAT:.LC%d",countdata);
			append(temp,code);
			append("\tcall    put",code);
			countdata = countdata +1;

	}

}
void print(node* p)
{
	if(p)
	{
		fwrite(p->data,1,strlen(p->data),fp);
		fwrite("\n", sizeof(char), 1, fp);
		print(p->next);
	}


}



int main(int argc, const char *argv[]) {

	for(int i=0;i<27;i++)
	{
		reg[i] = 0;
		type[i] = 0;
		regByte[i] =0;
		regString[i] = (char*)malloc(100);
		regString[i] = " ";
	}
	data = getnode(" ",NULL);
	code = getnode(".LBB2:",NULL);
	jump = getnode(".L2:",NULL);
	node *j3 = getnode(".L3",NULL);
	printf("%s\n", argv[1]);
    yyin = fopen(argv[1], "r");
	fp = fopen("asm.txt","w");


    if(yyin == NULL){
        printf("invalid input file\n");
    }
	do { 		
		if(yyin  == ' ' || yyin == '\t')
		continue;
		yyparse();
	} while(!feof(yyin));
	node *head = getnode(".Ldebug_abbrev0:",NULL);
	node *tail = getnode(".LBE3:",NULL);
	append("\tmov     eax, 0",tail);
	append("\tleave",tail);
	append(".LCFI2:",tail);
	append("\tret",tail);
	node *h = head;
	node *t = head;
	append(".Ldebug_info0:",t);
	append(".Ldebug_line0:",t);
	append(".Ltext0:",t);
	append("main:",t);
	append(".LFB0:",t);
	append("\tpush    rbp",t);
	append(".LCFI0:",t);
	append("\tmov     rbp, rsp",t);
	print(head);
	print(data);
	print(code);
	print(tail);
	fclose(fp);

	

	return 0;
}
void yyerror(char* s) {
	printf("Syntax error \n");
	yyparse();
}