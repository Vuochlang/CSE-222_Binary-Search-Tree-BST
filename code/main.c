//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: Vuochlang Chang                                                                                                            //
// Class: CSE222        Winter-2020     2419                                                                                        //
// Date: 02/25/2020                                                                                                                 //
// Assignment: PA4 - Plate3                                                                                                         //
// This code will implement a Binary Tree which is a tree data structure. Each node will have two children as the maximum number.   //
// The to children are referred to the left child (left-sub-tree) and the right child (right-sub-tree). This code will allow user to//
// 			_dump data out in LNR, NLR LRN order									                                                //
//			_check the height of the tee										                                                    //
//			_check if the tree is balanced										                                                    //
//			_delete any node (platenumber and its information) from the tree 					                                    //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "all.h"

int main(int argc, char **argv)
{       char str[100],plate[100], firstname[100], lastname[100];
        int e=0;
        char command1[100], command2[100];
        FILE *fp;

  	if(argc==1) //this will check to ensure that user is using the right format of commands
        {       printf("Usage: %s database\n",argv[0]);
                        return 1;
        }
        else if(argc==2)// check if the given database is able to access or not
        {       fp=fopen(argv[1],"r");
                if(fp==NULL)
                {       printf("Error: cannot open %s\n",argv[1]);
                        return 1;
                }

        }
        else
        {       printf("Usage: %s database\n",argv[0]);
                return 1;
        }

        Node root=NULL;//initialising root
        while(fgets(str,100,fp)!=NULL)//from the database, read and get each line of data and add to the tree with the given root 
        {       sscanf(str,"%s%s%s",plate,firstname,lastname);
                root=add(root,plate,firstname,lastname);
        }
        fclose(fp); //close the database file

        printf("Enter command or plate: ");

        while(fgets(str,100,stdin)!=NULL)//loop to run the program until user type Ctrl+D (EOF) to exit 
        {       e=0;
                e=sscanf(str,"%s%s",command1,command2);//get user commands
                if(e==1)//check if the command is *DUMP then call the function
                {       if(strcmp(command1,"*DUMP")==0)
                        {       nodeDump(root);
                        }
                        else
                        printf("Plate Not Found\n");
                }
                else if(e==2)//check if user input two commands, which suppose to be *DELETE with any platenumber
                {       if(strcmp(command1,"*DELETE")==0 && search(root,command2,firstname,lastname)==1)//if the plate exist, call delete function
                        {       root=delete(root,command2);
                                printf("SUCCESS\n");
                        }
                        else
                        printf("Plate Not Found\n");
                }
                else
                {       printf("Plate Not Found\n");
                }
        printf("Enter command or plate: ");//keep getting user command 
        }
        treeFree(root);//free all the memories and exit the program
        printf("\nFreeing memories\n");
return 0;
}

