  /**--------------------------------------------------------**/
  /**       T r a n s l a t i o n   Z to C (Standard)        **/
  /**             By Pr. D.E ZEGOUR                          **/
  /**             E S I - Algier                             **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/

  /* 2023/2024 
ALSDD TP 2  , TPZ 
By BELGUESMIA OUSSAMA & BELLOUL ZINE EL DINE 
from: 1CP7 */
#define RESET   "\e[m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD "\e[1m"
#define CLEAR "\033[2J"

   
   
  #include <stdio.h>
  #include <stdlib.h>
  #include <Time.h>
  #include <unistd.h>

  typedef int bool ;

  #define True 1
  #define False 0

  /** -Implementation- **\: LIST Of BINARY SERACH TREES OF STRUCTURES**/

  /** Structures **/

  typedef struct Tib Type_Tib  ;
  typedef Type_Tib * Typestr_Tib ;
  typedef int Type1_Tib  ;
  typedef bool Type2_Tib  ;
  struct Tib
    {
      Type1_Tib Field1 ;
      Type2_Tib Field2 ;
    };

  Type1_Tib Struct1_Tib ( Typestr_Tib S)
    {
      return  S->Field1 ;
    }

  Type2_Tib Struct2_Tib ( Typestr_Tib S)
    {
      return  S->Field2 ;
    }

  void Ass_struct1_Tib ( Typestr_Tib S, Type1_Tib Val )
    {
       S->Field1 = Val ;
    }

  void Ass_struct2_Tib ( Typestr_Tib S, Type2_Tib Val )
    {
       S->Field2 = Val ;
    }


  /** Binary search trees **/

  typedef Typestr_Tib Typeelem_ATib   ;
  typedef struct Noeud_ATib * Pointer_ATib ;

  struct Noeud_ATib
    {
      Typeelem_ATib  Val ;
      Pointer_ATib Fg ;
      Pointer_ATib Fd ;
      Pointer_ATib Pere ;
     } ;

  Typeelem_ATib Node_value_ATib( Pointer_ATib P )
    { return P->Val;   }

  Pointer_ATib Lc_ATib( Pointer_ATib P)
    { return P->Fg ; }

  Pointer_ATib Rc_ATib( Pointer_ATib P)
    { return P->Fd ; }

  Pointer_ATib Parent_ATib( Pointer_ATib P)
    { return P->Pere ; }

  void Ass_node_val_ATib ( Pointer_ATib P, Typeelem_ATib Val)
    {
      Typeelem_ATib _Temp ;
      _Temp = malloc(sizeof(Type_Tib));
      /* Global assignment of structure */
      _Temp->Field1 = Val->Field1;
      _Temp->Field2 = Val->Field2;
      Val = _Temp ;
       P->Val = Val ;
    }

  void Ass_lc_ATib( Pointer_ATib P, Pointer_ATib Q)
    { P->Fg =  Q;  }

  void Ass_rc_ATib( Pointer_ATib P, Pointer_ATib Q)
    { P->Fd =  Q ; }

  void Ass_parent_ATib( Pointer_ATib P, Pointer_ATib Q)
    { P->Pere =  Q ; }

  void Allocate_node_ATib( Pointer_ATib *P)
    {
      *P = (struct Noeud_ATib *) malloc( sizeof( struct Noeud_ATib))   ;
      (*P)->Val = malloc(sizeof(Type_Tib));
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Free_node_ATib( Pointer_ATib P)
    { free( P ) ; }


  /** Linked lists **/

  typedef Pointer_ATib Typeelem_LATib   ;
  typedef struct Maillon_LATib * Pointer_LATib ;

  struct Maillon_LATib
    {
      Typeelem_LATib  Val ;
      Pointer_LATib Suiv ;
    } ;

  Pointer_LATib Allocate_cell_LATib (Pointer_LATib *P)
    {
      *P = (struct Maillon_LATib *) malloc( sizeof( struct Maillon_LATib)) ;
      (*P)->Suiv = NULL;
    }

  void Ass_val_LATib(Pointer_LATib P, Typeelem_LATib Val)
    {
      P->Val = Val ;
    }

  void Ass_adr_LATib( Pointer_LATib P,  Pointer_LATib Q)
    {
      P->Suiv = Q ;
    }

  Pointer_LATib Next_LATib(  Pointer_LATib P)
    { return( P->Suiv ) ;  }

  Typeelem_LATib Cell_value_LATib( Pointer_LATib P)
    { return( P->Val) ; }

  void Free_LATib ( Pointer_LATib P)
    { free (P);}


  /** -Implementation- **\: ARRAY OF BINARY SERACH TREES OF STRUCTURES**/

  /** Arrays **/

  typedef Pointer_ATib Typeelem_V50_100ATib ;
  typedef Typeelem_V50_100ATib * Typevect_V50_100ATib ;

  Typeelem_V50_100ATib Element_V50_100ATib ( Typevect_V50_100ATib V , int I1 , int I2 )
    {
      return  *(V +  (I1-1)*100 + (I2-1)  ) ;
    }

  void Ass_element_V50_100ATib ( Typevect_V50_100ATib V  , int I1 , int I2,  Typeelem_V50_100ATib Val )
    {
      *(V +  (I1-1)*100 + (I2-1)  ) = Val ;
    }


  /** -Implementation- **\: ARRAY OF BINARY SERACH TREES OF STRUCTURES**/

  /** Arrays **/

  typedef Pointer_ATib Typeelem_V10ATib ;
  typedef Typeelem_V10ATib * Typevect_V10ATib ;

  Typeelem_V10ATib Element_V10ATib ( Typevect_V10ATib V , int I1  )
    {
      return  *(V +  (I1-1)  ) ;
    }

  void Ass_element_V10ATib ( Typevect_V10ATib V  , int I1 ,  Typeelem_V10ATib Val )
    {
      *(V +  (I1-1)  ) = Val ;
    }


  /** -Implementation- **\: ARRAY OF INTEGERS**/

  /** Arrays **/

  typedef int Typeelem_V100i ;
  typedef Typeelem_V100i * Typevect_V100i ;

  Typeelem_V100i Element_V100i ( Typevect_V100i V , int I1  )
    {
      return  *(V +  (I1-1)  ) ;
    }

  void Ass_element_V100i ( Typevect_V100i V  , int I1 ,  Typeelem_V100i Val )
    {
      *(V +  (I1-1)  ) = Val ;
    }


  /** -Implementation- **\: STACK OF BINARY SERACH TREES OF STRUCTURES**/
  /** Stacks**/

  typedef Pointer_ATib Typeelem_PATib ;
  typedef struct Maillon_PATib * Pointer_PATib ;
  typedef   Pointer_PATib  Typepile_PATib  ;

  struct Maillon_PATib
    {
      Typeelem_PATib  Val ;
      Pointer_PATib Suiv ;
    } ;

  void Createstack_PATib( Pointer_PATib *P )
    { *P = NULL ; }

  bool Empty_stack_PATib ( Pointer_PATib P )
    { return  (P == NULL ); }

  void Push_PATib ( Pointer_PATib *P,  Typeelem_PATib Val )
    {
      Pointer_PATib Q;

      Q = (struct Maillon_PATib *) malloc( sizeof( struct Maillon_PATib))   ;
      Q->Val = Val ;
      Q->Suiv = *P;
      *P = Q;
    }

  void Pop_PATib ( Pointer_PATib *P,  Typeelem_PATib *Val )
    {
      Pointer_PATib Sauv;

      if (! Empty_stack_PATib (*P) )
        {
          *Val = (*P)->Val ;
          Sauv = *P;
          *P = (*P)->Suiv;
          free(Sauv);
        }
      else printf ("%s \n", "Stack is empty");
    }


  /** -Implementation- **\: QUEUE OF INTEGERS**/
  /** Queues **/

  typedef int Typeelem_Fi ;
  typedef  struct Filedattente_Fi * Pointer_Fi ;
  typedef  struct Maillon_Fi * Ptliste_Fi ;

  struct Maillon_Fi
    {
      Typeelem_Fi Val ;
      Ptliste_Fi Suiv  ;
    };

  struct Filedattente_Fi
    {
      Ptliste_Fi Tete, Queue ;
    };

  void Createqueue_Fi ( Pointer_Fi *Fil   )
    {
      *Fil = (struct Filedattente_Fi *) malloc( sizeof( struct Filedattente_Fi)) ;
      (*Fil)->Tete = NULL ;
      (*Fil)->Queue = NULL ;
    }

  bool Empty_queue_Fi (Pointer_Fi Fil  )
    { return  Fil->Tete == NULL ;}

  void Enqueue_Fi ( Pointer_Fi Fil , Typeelem_Fi Val   )
    {
      Ptliste_Fi Q;

      Q = (struct Maillon_Fi *) malloc( sizeof( struct Maillon_Fi))   ;
      Q->Val = Val ;
      Q->Suiv = NULL;
      if ( ! Empty_queue_Fi(Fil) )
        Fil->Queue->Suiv = Q ;
      else Fil->Tete = Q;
        Fil->Queue = Q;
    }

  void Dequeue_Fi (Pointer_Fi Fil, Typeelem_Fi *Val )
    {
      if (! Empty_queue_Fi(Fil) )
        {
          *Val = Fil->Tete->Val ;
          Fil->Tete =  Fil->Tete->Suiv;
        }
      else printf ("%s \n", "Queue is empty");
    }


  /** -Implementation- **\: ARRAY OF BOOLEANS**/

  /** Arrays **/

  typedef bool Typeelem_V1000b ;
  typedef Typeelem_V1000b * Typevect_V1000b ;

  Typeelem_V1000b Element_V1000b ( Typevect_V1000b V , int I1  )
    {
      return  *(V +  (I1-1)  ) ;
    }

  void Ass_element_V1000b ( Typevect_V1000b V  , int I1 ,  Typeelem_V1000b Val )
    {
      *(V +  (I1-1)  ) = Val ;
    }


  /** -Implementation- **\: STACK OF INTEGERS**/
 /** Stacks**/ 

  typedef int Typeelem_Pi ;
  typedef struct Maillon_Pi * Pointer_Pi ;
  typedef   Pointer_Pi  Typepile_Pi  ;

  struct Maillon_Pi
    {
      Typeelem_Pi  Val ;
      Pointer_Pi Suiv ;
    } ;

  void Createstack_Pi( Pointer_Pi *P )
    { *P = NULL ; }

  bool Empty_stack_Pi ( Pointer_Pi P )
    { return  (P == NULL ); }

  void Push_Pi ( Pointer_Pi *P,  Typeelem_Pi Val )
    {
      Pointer_Pi Q;

      Q = (struct Maillon_Pi *) malloc( sizeof( struct Maillon_Pi))   ;
      Q->Val = Val ;
      Q->Suiv = *P;
      *P = Q;
    }

  void Pop_Pi ( Pointer_Pi *P,  Typeelem_Pi *Val )
    {
      Pointer_Pi Sauv;

      if (! Empty_stack_Pi (*P) )
        {
          *Val = (*P)->Val ;
          Sauv = *P;
          *P = (*P)->Suiv;
          free(Sauv);
        }
      else printf ("%s \n", "Stack is empty");
    }

  /** Variables of main program **/
  Pointer_LATib Tmp1=NULL;
  Pointer_LATib Tmp2=NULL;
  int N;  // Number of elements of tress
  int M;  //number of trees
  int T;  //Counter
  int Counter1; //Counter
  int Tree_number;  //Active tree number
  Pointer_ATib A=NULL;  //Pointer to BST used to traverse tree
  Pointer_ATib Index_l=NULL;  //Pointer to BST used to traverse tree
  bool Test;  // boolean to save check tree result
  bool Firstelement;  // indicate the begining of linked list 
  Typevect_V50_100ATib Result_array;  // array of [40,100] where each line represents the result of tree traversal
  // first tree traversals are in 1,2,3,4 lines 2nd tree in 5,6,7,8 lines....
  Typevect_V10ATib Trees_array; // array of 10 pointers to bst each points to a tree root
  Typevect_V100i Testing_array; // array contrains the result of checking traversal after calling checking functions
  int _Px1;
  int _Px2;
  int _Px3;
  int _Px4;

  /** Standard functions **/

  int Aleanombre( int N )
    { return ( rand() % N ); }


  /** Function prototypes **/

  void Randombst (Pointer_ATib *T , int *Nn);
  void Insertbst (Pointer_ATib *T , int *V , bool *B);
  void Searchbst (Pointer_ATib *T , int *V , Pointer_ATib *Res , Pointer_ATib *Parentt);
  void Inorder (Pointer_ATib *T);
  bool  Checkbst (Pointer_ATib *T , int *N_elements) ;
  void Byb_ltr (Pointer_ATib *Byb_tr , int *Ltr_number);
  void Byb_rtl (Pointer_ATib *Byb_tr , int *Rtl_number);
  void Check_correctness_byb_ltr (Pointer_ATib *Tr);
  void Check_correctness_byb_rtl (Pointer_ATib *Tr);
  void Leafbyleaf_ltr (Pointer_ATib *Root , int *Index1);
  void Leafbyleaf_rtl (Pointer_ATib *Root , int *Lbl_ltr_index);
  bool  Left_stop_test (Pointer_ATib *Leaf_noud1) ;
  bool  None_stop_test (Pointer_ATib *Leaf_noud2) ;
  void Resettree (Pointer_ATib *T);
  Pointer_ATib Copytree (Pointer_ATib *Copytr) ;
  void Checkcorectness_lbl_ltr (Pointer_ATib *Root);
  void Checkcorectness_lbl_rtl (Pointer_ATib *Root);
  void Write_traversal (int *Index);
  void Check_correctness (int *Index);
  void Mainmenu();

  /*Action that create a bst of exactly 'Nn' element*/
  void Randombst (Pointer_ATib *T , int *Nn)
    {
      /** Local variables **/
      int H;
      bool Test_insert;
      int _Px1;

      /** Body of function **/
     H  =  0 ;
     Test_insert  =  False ;
     while( ( H < *Nn )) {
       _Px1 =  Aleanombre(999 ) + 1 ;
       Insertbst ( & *T , &_Px1, & Test_insert ) ;
       if( ( Test_insert )) {
         H  =  H + 1 ;
         Test_insert  =  False ;
        
       } ;
      
     } ;
    
    }
  /*Action to insert in bst*/
  void Insertbst (Pointer_ATib *T , int *V , bool *B)
    {
      /** Local variables **/
      Pointer_ATib P=NULL;
      Pointer_ATib Parentt=NULL;
      Pointer_ATib Tmp=NULL;
      Typestr_Tib Vv;

      /** Body of function **/
     Vv = malloc(sizeof(Type_Tib));
     *B  =  False ;
     if( ( *T == NULL )) {
       Ass_struct1_Tib ( Vv  , *V ) ;
       Ass_struct2_Tib ( Vv  , False ) ;
       Allocate_node_ATib (& Tmp ) ;
       Ass_node_val_ATib ( Tmp , Vv ) ;
       *B  =  True ;
       *T  =  Tmp ;
       }
     else
       {
       Searchbst ( & *T , & *V , & P , & Parentt ) ;
       if( P == NULL) {
         Ass_struct1_Tib ( Vv  , *V ) ;
         Ass_struct2_Tib ( Vv  , False ) ;
         Allocate_node_ATib (& Tmp ) ;
         Ass_node_val_ATib ( Tmp , Vv ) ;
         *B  =  True ;
         if( Struct1_Tib ( Node_value_ATib ( Parentt )  ) < *V) {
           Ass_rc_ATib ( Parentt , Tmp ); }
         else
           {
           Ass_lc_ATib ( Parentt , Tmp );
         } ;
         }
       else
         {
         *B  =  False ;
        
       } ;
      
     } ;
    
    }
  /*an action to serash fo value in bst and return the node with the value and its parent 
   if res=null then the value doesn't exist in the tree*/
  void Searchbst (Pointer_ATib *T , int *V , Pointer_ATib *Res , Pointer_ATib *Parentt)
    {
      /** Local variables **/
      Pointer_ATib P=NULL;
      Pointer_ATib Q=NULL;
      bool Found;

      /** Body of function **/
     if( *T == NULL) {
       *Res  =  NULL ;
       *Parentt  =  NULL ;
       }
     else
       {
       Q  =  NULL ;
       P  =  *T ;
       Found  =  False ;
       while( ( P != NULL ) && ( ! Found )) {
         if( Struct1_Tib ( Node_value_ATib ( P )  ) == *V) {
           Found  =  True ;
           }
         else
           {
           Q  =  P ;
           if( Struct1_Tib ( Node_value_ATib ( P )  ) < *V) {
             P  =  Rc_ATib ( P ) ;
             }
           else
             {
             P  =  Lc_ATib ( P ) ;
            
           }
         }
       } ;
       *Res  =  P ;
       *Parentt  =  Q ;
      
     }
    }
  void Inorder (Pointer_ATib *T)
    {
      /** Local variables **/
      Pointer_ATib P=NULL;
      Pointer_PATib S=NULL;
      bool Stop;

      /** Body of function **/
     Stop  =  False ;
     P  =  *T ;
     Createstack_PATib (& S ) ;
     while( ! Stop) {
       while( P != NULL) {
         Push_PATib (& S , P ) ;
         P  =  Lc_ATib ( P ) ;
        
       } ;
       if( ! Empty_stack_PATib ( S )) {
         Pop_PATib (& S , &P ) ;
         printf ( "%s %d%s->",BOLD, Struct1_Tib(Node_value_ATib(P)),GREEN ) ;
         printf("%s",RESET);
         P  =  Rc_ATib ( P ) ;
         }
       else
         {
         Stop  =  True ;
        
       } ;
      
     } ;    
    }
  /*function checks if bst is builded correctly using inorder traversal and returns a boolean 
   which is true if and only if each element is inferior than its next inorder and returns the number of elements*/
  bool  Checkbst (Pointer_ATib *T , int *N_elements)
    {
      /** Local variables **/
      bool  Checkbst2 ;
     Pointer_ATib P=NULL;
      Pointer_ATib Q=NULL;
      Pointer_PATib S=NULL;
      bool Stop;
      bool Testb;

      /** Body of function **/
     *N_elements  =  0 ;
     Stop  =  False ;
     P  =  *T ;
     Testb  =  True ;
     Q  =  NULL ;
     while( ( ! Stop )) {
       while( P != NULL) {
         Push_PATib (& S , P ) ;
         if( Lc_ATib ( P ) != NULL) {
          ;
         } ;
         P  =  Lc_ATib ( P ) ;
        
       } ;
       if( ! Empty_stack_PATib ( S )) {
         Pop_PATib (& S , &P ) ;
         *N_elements  =  *N_elements + 1 ;
        /*Compare Q with its next inorder P 'if p<=q return false*/
         if( Q != NULL) {
           if( Struct1_Tib ( Node_value_ATib ( Q )  ) >= Struct1_Tib ( Node_value_ATib ( P )  )) {
             Testb  =  False ;
            
           } ;
          
         } ;
         Q  =  P ;
         P  =  Rc_ATib ( P ) ;
         }
       else
         {
         Stop  =  True ;
        
       } ;
      
     } ;
     Checkbst2  =  Testb ;    
     return Checkbst2 ;
    }
  /*action to peform branch by branch  from left to right */
  void Byb_ltr (Pointer_ATib *Byb_tr , int *Ltr_number)
    {
      /** Local variables **/
      Pointer_PATib Next_branch=NULL;
      Pointer_PATib Current_branch=NULL;
      Pointer_ATib A=NULL;
      bool Stop;
      int Ltr_index;

      /** Body of function **/
     Ltr_index  =  1 ;
     if( *Byb_tr != NULL) {
       Stop  =  False ;
       A  =  *Byb_tr ;
      /*stack to save non visited right branches to visit it after the left branch*/
       Createstack_PATib (& Next_branch ) ;
      /*stack contains the branch */
       Createstack_PATib (& Current_branch ) ;
       while( ( ! Stop )) {
        /*decend to the leftmost leaf and push branch nodes*/
         while( ( A != NULL )) {
           Push_PATib (& Current_branch , A ) ;
          /*if the element has no LC and it is not a leaf we continue to right*/
           if( Rc_ATib ( A ) != NULL) {
             if( Lc_ATib ( A ) == NULL) {
               A  =  Rc_ATib ( A ) ;
               }
            /*save right non visited node*/
             else
               {
               Push_PATib (& Next_branch , Rc_ATib ( A ) ) ;
               A  =  Lc_ATib ( A ) ;
              
             } ;
             }
           else
             {
             A  =  Lc_ATib ( A ) ;
            
           } ;
          
         } ;
        /*pop branch elements and save them to result array*/
         while( ( ! Empty_stack_PATib ( Current_branch ) )) {
           Pop_PATib (& Current_branch , &A ) ;
           Ass_element_V50_100ATib ( Result_array , *Ltr_number , Ltr_index   , A ) ;
           Ltr_index  =  Ltr_index + 1 ;
          
         } ;
        /*visit right branches*/
         if( ! Empty_stack_PATib ( Next_branch )) {
           Pop_PATib (& Next_branch , &A ) ;
           }
         else
           {
           Stop  =  True ;
          
         }
       } ;
      
     } ;
    
    }
  /*action to peform branch by branch  from right to left */
  void Byb_rtl (Pointer_ATib *Byb_tr , int *Rtl_number)
    {
      /** Local variables **/
      Pointer_PATib Next_branch=NULL;
      Pointer_PATib Current_branch=NULL;
      Pointer_ATib A=NULL;
      bool Stop;
      bool Found;
      int Rtl_index;

      /** Body of function **/
     Rtl_index  =  1 ;
     if( *Byb_tr != NULL) {
       Stop  =  False ;
       A  =  *Byb_tr ;
      /*stack to save non visited right branches to visit it after the right branch*/
       Createstack_PATib (& Next_branch ) ;
      /*stack contains the branch */
       Createstack_PATib (& Current_branch ) ;
       while( ( ! Stop )) {
         while( ( A != NULL )) {
           Push_PATib (& Current_branch , A ) ;
          /*decend to the rightmost leaf and push branch nodes*/
          /*if the element has no RC and it is not a leaf we continue to left*/
           if( Lc_ATib ( A ) != NULL) {
             if( Rc_ATib ( A ) == NULL) {
               A  =  Lc_ATib ( A ) ;
               }
            /*save left non visited node*/
             else
               {
               Push_PATib (& Next_branch , Lc_ATib ( A ) ) ;
               A  =  Rc_ATib ( A ) ;
              
             } ;
             }
           else
             {
             A  =  Rc_ATib ( A ) ;
            
           } ;
          
         } ;
        /*pop branch elements and save them to result array*/
         while( ( ! Empty_stack_PATib ( Current_branch ) )) {
           Pop_PATib (& Current_branch , &A ) ;
           Ass_element_V50_100ATib ( Result_array , *Rtl_number , Rtl_index   , A ) ;
           Rtl_index  =  Rtl_index + 1 ;
          
         } ;
        /*visit left branches*/
         if( ! Empty_stack_PATib ( Next_branch )) {
           Pop_PATib (& Next_branch , &A ) ;
           }
         else
           {
           Stop  =  True ;
          
         }
       } ;
      
     } ;
    
    }
  /*Action checks the correctness of bransh by bransh from left to right traversal 
by saving all branches from left to right in a linked list then delete duplicates*/
  void Check_correctness_byb_ltr (Pointer_ATib *Tr)
    {
      /** Local variables **/
      Pointer_ATib P=NULL;
      Pointer_ATib K=NULL;
      Pointer_LATib Brancheslist=NULL;
      Pointer_LATib L=NULL;
      Pointer_LATib Q=NULL;
      int V;
      int V2;
      Pointer_Fi Leafsqueue=NULL;
      Pointer_PATib S=NULL;
      bool First;
      bool Stop;
      bool Found;
      Typevect_V1000b H_tab;

      /** Body of function **/
     H_tab = malloc(1000 * sizeof(int));
     K  =  NULL ;
     P  =  *Tr ;
     Createstack_PATib (& S ) ;
     Createqueue_Fi (& Leafsqueue ) ;
     Stop  =  False ;
     First  =  True ;
    /*we collect all leafs values from left to right in a queue 'leafsqueue*/
    /*we desed to the left most leaf and add it to the queue*/
     while( ( ! Stop )) {
       while( ( P != NULL )) {
         K  =  P ;
        /*if there is a branch in the right side we save its path to get the leaf there*/
         if( ( Rc_ATib ( P ) != NULL )) {
           Push_PATib (& S , Rc_ATib ( P ) ) ;
          
         } ;
         P  =  Lc_ATib ( P ) ;
        
       } ;
       if( Rc_ATib ( K ) == NULL) {
         Enqueue_Fi ( Leafsqueue , Struct1_Tib ( Node_value_ATib ( K )  ) ) ;
        
       } ;
       if( ( ! Empty_stack_PATib ( S ) )) {
         Pop_PATib (& S , &P ) ;
         }
       else
         {
         Stop  =  True ;
        
       } ;
      
     } ;
    /*we know that all branches are a path from root to a leaf so if we use a search similar algorithm 
to go from the root to a leaf we have a branche and we save it stack to save in the linked list from bottom to top 
++ number of paths=number of leafs*/
     L  =  NULL ;
    /*we dequeue leaf by leaf from left to write*/
     while( ( ! Empty_queue_Fi ( Leafsqueue ) )) {
       Dequeue_Fi ( Leafsqueue , &V ) ;
       P  =  *Tr ;
      /*using search similar algorith we save the path to the leaf*/
       while( ( P != NULL )) {
         Push_PATib (& S , P ) ;
         if( ( Struct1_Tib ( Node_value_ATib ( P )  ) == V )) {
           P  =  NULL ;
           }
         else
           {
           if( ( V > Struct1_Tib ( Node_value_ATib ( P )  ) )) {
             P  =  Rc_ATib ( P ) ;
             }
           else
             {
             P  =  Lc_ATib ( P ) ;
            
           } ;
          
         } ;
        
       } ;
      /*we save the branch in the linked list*/
       while( ( ! Empty_stack_PATib ( S ) )) {
         Pop_PATib (& S , &P ) ;
         Allocate_cell_LATib (& L ) ;
         Ass_val_LATib ( L , P ) ;
         if( ( First )) {
           Brancheslist  =  L ;
           Q  =  L ;
           First  =  False ;
           }
         else
           {
           Ass_adr_LATib ( Q , L ) ;
           Q  =  L ;
          
         } ;
        
       } ;
      
     } ;
    /*we use a hash table to delete duplicates from the linked list in efficient way 
where the index of value N  is N 
'in our test values are between 1 and 1000' and it can be exeeded by extending the hash table size*/
    /*we initialise all values as false in the hash table (which means not inserted)*/
     for( V  =  1 ;V <=  1000 ; ++V){
       Ass_element_V1000b ( H_tab , V   , False );
     } ;
     V  =  1 ;
     L  =  Brancheslist ;
     Q  =  NULL ;
     while( ( L != NULL )) {
       V2  =  Struct1_Tib ( Node_value_ATib ( Cell_value_LATib ( L ) )  ) ;
      /*we check if the value is inserted or not using the hash table*/
       if( ( Element_V1000b ( H_tab , V2   ) == False )) {
         Ass_element_V100i ( Testing_array , V   , V2 ) ;
         V  =  V + 1 ;
        /*after inserting an element we set its emplacement to true in the hash table*/
         Ass_element_V1000b ( H_tab , V2   , True ) ;
        
       } ;
       Q  =  L ;
       L  =  Next_LATib ( L ) ;
       Free_LATib ( Q ) ;
      /* free the cell we alredy treat */
      
     } ;
    
    }
  /*Action checks the correctness of bransh by bransh from right to left traversal 
we used same algorithm for (from left to right) traversal by just replacing the leafsqueue by a stack 
so we have the leafs ordred from right to left and do the same process in the mentioned algorithm*/
  void Check_correctness_byb_rtl (Pointer_ATib *Tr)
    {
      /** Local variables **/
      Pointer_ATib P=NULL;
      Pointer_ATib K=NULL;
      Pointer_LATib Brancheslist=NULL;
      Pointer_LATib L=NULL;
      Pointer_LATib Q=NULL;
      int V;
      int V2;
      Pointer_Pi Leafsstack=NULL;
      Pointer_PATib S=NULL;
      bool First;
      bool Stop;
      bool Found;
      Typevect_V1000b H_tab;

      /** Body of function **/
     H_tab = malloc(1000 * sizeof(int));
     K  =  NULL ;
     P  =  *Tr ;
     Createstack_PATib (& S ) ;
     Createstack_Pi (& Leafsstack ) ;
     Stop  =  False ;
     First  =  True ;
     while( ( ! Stop )) {
       while( ( P != NULL )) {
         K  =  P ;
         if( ( Rc_ATib ( P ) != NULL )) {
           Push_PATib (& S , Rc_ATib ( P ) ) ;
          
         } ;
         P  =  Lc_ATib ( P ) ;
        
       } ;
       if( Rc_ATib ( K ) == NULL) {
         Push_Pi (& Leafsstack , Struct1_Tib ( Node_value_ATib ( K )  ) ) ;
        
       } ;
       if( ( ! Empty_stack_PATib ( S ) )) {
         Pop_PATib (& S , &P ) ;
         }
       else
         {
         Stop  =  True ;
        
       } ;
      
     } ;
     L  =  NULL ;
     while( ( ! Empty_stack_Pi ( Leafsstack ) )) {
       Pop_Pi (& Leafsstack , &V ) ;
       P  =  *Tr ;
       while( ( P != NULL )) {
         Push_PATib (& S , P ) ;
         if( ( Struct1_Tib ( Node_value_ATib ( P )  ) == V )) {
           P  =  NULL ;
           }
         else
           {
           if( ( V > Struct1_Tib ( Node_value_ATib ( P )  ) )) {
             P  =  Rc_ATib ( P ) ;
             }
           else
             {
             P  =  Lc_ATib ( P ) ;
            
           } ;
          
         } ;
        
       } ;
       while( ( ! Empty_stack_PATib ( S ) )) {
         Pop_PATib (& S , &P ) ;
         Allocate_cell_LATib (& L ) ;
         Ass_val_LATib ( L , P ) ;
         if( ( First )) {
           Brancheslist  =  L ;
           Q  =  L ;
           First  =  False ;
           }
         else
           {
           Ass_adr_LATib ( Q , L ) ;
           Q  =  L ;
          
         } ;
        
       } ;
      
     } ;
     for( V  =  1 ;V <=  1000 ; ++V){
       Ass_element_V1000b ( H_tab , V   , False );
     } ;
     V  =  1 ;
     L  =  Brancheslist ;
     Q  =  NULL ;
     while( ( L != NULL )) {
       V2  =  Struct1_Tib ( Node_value_ATib ( Cell_value_LATib ( L ) )  ) ;
       if( ( Element_V1000b ( H_tab , V2   ) == False )) {
         Ass_element_V100i ( Testing_array , V   , V2 ) ;
         V  =  V + 1 ;
         Ass_element_V1000b ( H_tab , V2   , True ) ;
        
       } ;
       Q  =  L ;
       L  =  Next_LATib ( L ) ;
       Free_LATib ( Q ) ;
      /* free the cell we already treat*/
      
     } ;
    
    }
  /*Action do the leafs first from left to write traversl and save result in result_array*/
  void Leafbyleaf_ltr (Pointer_ATib *Root , int *Index1)
    {
      /** Local variables **/
      Pointer_ATib P=NULL;
      Pointer_ATib K=NULL;
      Pointer_PATib S=NULL;
      bool Stop;
      bool Found;
      int Index;
      Pointer_ATib _Px1=NULL;
      Pointer_ATib _Px2=NULL;

      /** Body of function **/
     Resettree ( & *Root ) ;
     K  =  NULL ;
     Index  =  1 ;
     P  =  *Root ;
    /*stack to save right childs to visit right branches after done with left one*/
     Createstack_PATib (& S ) ;
     Stop  =  False ;
     while( ( ! Stop )) {
       while( ( ! Left_stop_test ( & P ) )) {
         K  =  P ;
         _Px1 =  Rc_ATib ( P ) ;
        /*Push RC of P if it is not null and not visited*/
         if( ( None_stop_test ( &_Px1) )) {
           Push_PATib (& S , Rc_ATib ( P ) ) ;
          
         } ;
         P  =  Lc_ATib ( P ) ;
        
       } ;
      /*thanks to the loop we know that LC(k) is null or visited, then if RC(k) is visited or null 
           k is the next element to visit we add it to the result queue and mark it as visited*/
       _Px2 =  Rc_ATib ( K ) ;
       if( ! None_stop_test ( &_Px2)) {
         if( ( *Index1 <= 40 )) {
           Ass_element_V50_100ATib ( Result_array , *Index1 , Index   , K ) ;
          
         } ;
         Index  =  Index + 1 ;
         Ass_struct2_Tib ( Node_value_ATib ( K )  , True ) ;
        
       } ;
      /*visited the right bransh*/
       if( ( ! Empty_stack_PATib ( S ) )) {
         Pop_PATib (& S , &P ) ;
         }
       else
         {
        /*last element to visit is the root if it is treated we exit the loop*/
         if( ( K == *Root )) {
           Stop  =  True ;
           }
        /*re-visit the tree after set all visited nodes 'visited filed to true*/
         else
           {
           P  =  *Root ;
          
         } ;
        
       } ;
      
     } ;
    
    }
  /*Action do the leafs first from right to left traversl and save result in result_array*/
  void Leafbyleaf_rtl (Pointer_ATib *Root , int *Lbl_ltr_index)
    {
      /** Local variables **/
      Pointer_ATib P=NULL;
      Pointer_ATib K=NULL;
      Pointer_PATib S=NULL;
      bool Stop;
      bool Found;
      int Index;
      Pointer_ATib _Px1=NULL;
      Pointer_ATib _Px2=NULL;

      /** Body of function **/
     Resettree ( & *Root ) ;
     K  =  NULL ;
     Index  =  1 ;
     P  =  *Root ;
    /*stack to save left childs to visit left branches after done with right one*/
     Createstack_PATib (& S ) ;
     Stop  =  False ;
     while( ( ! Stop )) {
       while( ( ! Left_stop_test ( & P ) )) {
         K  =  P ;
        /*Push LC of P if it is not null and not visited*/
         _Px1 =  Lc_ATib ( P ) ;
         if( ( None_stop_test ( &_Px1) )) {
           Push_PATib (& S , Lc_ATib ( P ) ) ;
          
         } ;
         P  =  Rc_ATib ( P ) ;
        
       } ;
      /*thanks to the loop we know that RC(k) is null or visited, then if LC(k) is visited or null 
           k is the next element to visit we add it to the result queue and mark it as visited*/
       _Px2 =  Lc_ATib ( K ) ;
       if( ! None_stop_test ( &_Px2)) {
         Ass_element_V50_100ATib ( Result_array , *Lbl_ltr_index , Index   , K ) ;
         Index  =  Index + 1 ;
         Ass_struct2_Tib ( Node_value_ATib ( K )  , True ) ;
        
       } ;
      /*visited the left bransh*/
       if( ( ! Empty_stack_PATib ( S ) )) {
         Pop_PATib (& S , &P ) ;
         }
       else
         {
        /*last element to visit is the root if it is treated we exit the loop*/
         if( ( K == *Root )) {
           Stop  =  True ;
           }
        /*re-visit the tree after set all visited nodes 'visited filed to true*/
         else
           {
           P  =  *Root ;
          
         } ;
        
       } ;
      
     } ;
    
    }
  /*a function return a boolean which is true if and only if the enter parameter is visited or null*/
  bool  Left_stop_test (Pointer_ATib *Leaf_noud1)
    {
      /** Local variables **/
      bool  Left_stop_test2 ;
      bool Leaf_test;

      /** Body of function **/
     Leaf_test  =  False ;
     if( ( *Leaf_noud1 == NULL )) {
       Leaf_test  =  True ;
       }
     else
       {
       if( ( Struct2_Tib ( Node_value_ATib ( *Leaf_noud1 )  ) )) {
         Leaf_test  =  True ;
        
       } ;
      
     } ;
     Left_stop_test2  =  Leaf_test ;
    
     return Left_stop_test2 ;
    }
  /*a function return a boolean which is true if and only if the enter parameter (node) is not null and not visited*/
  bool  None_stop_test (Pointer_ATib *Leaf_noud2)
    {
      /** Local variables **/
      bool  None_stop_test2 ;
      bool Leaf_test2;

      /** Body of function **/
     Leaf_test2  =  False ;
     if( ( *Leaf_noud2 != NULL )) {
       if( ( ! Struct2_Tib ( Node_value_ATib ( *Leaf_noud2 )  ) )) {
         Leaf_test2  =  True ;
        
       } ;
      
     } ;
     None_stop_test2  =  Leaf_test2 ;
    
     return None_stop_test2 ;
    }
  /*Action visite all the nodes of the tree (inorder) and reset all 'visited' field to false*/
  void Resettree (Pointer_ATib *T)
    {
      /** Local variables **/
      Pointer_ATib P=NULL;
      Pointer_PATib S=NULL;
      bool Stop;

      /** Body of function **/
     Stop  =  False ;
     P  =  *T ;
     Createstack_PATib (& S ) ;
     while( ! Stop) {
       while( P != NULL) {
         Push_PATib (& S , P ) ;
         P  =  Lc_ATib ( P ) ;
        
       } ;
       if( ! Empty_stack_PATib ( S )) {
         Pop_PATib (& S , &P ) ;
         Ass_struct2_Tib ( Node_value_ATib ( P )  , False ) ;
         P  =  Rc_ATib ( P ) ;
         }
       else
         {
         Stop  =  True ;
        
       } ;
      
     } ;
    
    }
  Pointer_ATib Copytree (Pointer_ATib *Copytr)
    {
      /** Local variables **/
     Pointer_ATib Copytree2 =NULL;
      Pointer_ATib Newroot=NULL;
      Typestr_Tib Vv;
      Pointer_ATib _Px1=NULL;
      Pointer_ATib _Px2=NULL;

      /** Body of function **/
     Vv = malloc(sizeof(Type_Tib));
     if( ( *Copytr == NULL )) {
       Copytree2  =  NULL ;
       }
     else
       {
       Allocate_node_ATib (& Newroot ) ;
       Ass_struct1_Tib ( Vv  , Struct1_Tib ( Node_value_ATib ( *Copytr )  ) ) ;
       Ass_struct2_Tib ( Vv  , False ) ;
       Ass_node_val_ATib ( Newroot , Vv ) ;
       _Px1 =  Lc_ATib ( *Copytr ) ;
       Ass_lc_ATib ( Newroot , Copytree ( &_Px1) ) ;
       _Px2 =  Rc_ATib ( *Copytr ) ;
       Ass_rc_ATib ( Newroot , Copytree ( &_Px2) ) ;
       Copytree2  =  Newroot ;
      
     } ;
    
     return Copytree2 ;
    }
  /* Verify the leafs traversal first from left to write */
  void Checkcorectness_lbl_ltr (Pointer_ATib *Root)
    {
      /** Local variables **/
      Pointer_ATib P=NULL;
      Pointer_ATib K=NULL;
      Pointer_ATib Lbl_ltr_root=NULL;
      Pointer_ATib Gp=NULL;
      Pointer_PATib S=NULL;
      Pointer_PATib Parent_s=NULL;
      bool Stop;
      bool Found;
      bool First;
      int Index;

      /** Body of function **/
     Index  =  1 ;
     First  =  True ;
    /*Make a copy of the tree before doing the test beacause we need to delete all the nodes*/
     Lbl_ltr_root  =  Copytree ( & *Root ) ;
     K  =  NULL ;
     P  =  Lbl_ltr_root ;
     Createstack_PATib (& S ) ;
    /*A stack containing the right childs when decending to the left side to visit the righ bransh after*/
     Createstack_PATib (& Parent_s ) ;
    /*A stack containing the parent to have access to it when pop from stack S*/
     Stop  =  False ;
     while( ( ! Stop )) {
       while( ( P != NULL )) {
         Gp  =  K ;
         K  =  P ;
        /*save the right child and its parent to visit the right branch after done with left one*/
         if( ( Rc_ATib ( P ) != NULL )) {
           Push_PATib (& Parent_s , P ) ;
           Push_PATib (& S , Rc_ATib ( P ) ) ;
          
         } ;
         P  =  Lc_ATib ( P ) ;
        
       } ;
      /*Thanks to the loop we know that lc(k)=p=null then if rc(k)=null, k is a leaf*/
       if( Rc_ATib ( K ) == NULL) {
         Ass_element_V100i ( Testing_array , Index   , Struct1_Tib ( Node_value_ATib ( K )  ) ) ;
        /*add the element to result array*/
         Index  =  Index + 1 ;
        /*if the parent is not null we update the parent child field pointing to K to null then free K*/
         if( ( Gp != NULL )) {
           if( ( K == Rc_ATib ( Gp ) )) {
             Ass_rc_ATib ( Gp , NULL ) ;
             }
           else
             {
             Ass_lc_ATib ( Gp , NULL ) ;
            
           } ;
          
         } ;
         Free_node_ATib ( K ) ;
        
       } ;
      /*visit the right bransh*/
       if( ( ! Empty_stack_PATib ( S ) )) {
         Pop_PATib (& S , &P ) ;
         Pop_PATib (& Parent_s , &K ) ;
         }
       else
         {
        /*last element to visit is the root if it is treated we exit the loop*/
         if( ( K == Lbl_ltr_root )) {
           Stop  =  True ;
           }
        /*we re-visit the tree after deleting visited leaves*/
         else
           {
           P  =  Lbl_ltr_root ;
           K  =  NULL ;
          
         } ;
        
       } ;
      
     } ;
    
    }
  /* Verify the leafs traversal first from right to left */
  void Checkcorectness_lbl_rtl (Pointer_ATib *Root)
    {
      /** Local variables **/
      Pointer_ATib P=NULL;
      Pointer_ATib K=NULL;
      Pointer_ATib Lbl_ltr_root=NULL;
      Pointer_ATib Gp=NULL;
      Pointer_PATib S=NULL;
      Pointer_PATib Parent_s=NULL;
      bool Stop;
      bool Found;
      bool First;
      int Index;

      /** Body of function **/
     Index  =  1 ;
     First  =  True ;
    /*Make a copy of the tree before doing the test beacause we need to delete all the nodes*/
     Lbl_ltr_root  =  Copytree ( & *Root ) ;
     K  =  NULL ;
     P  =  Lbl_ltr_root ;
     Createstack_PATib (& S ) ;
    /*A stack containing the right childs when decending to the left side to visit the left bransh after*/
     Createstack_PATib (& Parent_s ) ;
    /*A stack containing the parent to have access to it when pop from stack S*/
     Stop  =  False ;
     while( ( ! Stop )) {
       while( ( P != NULL )) {
         Gp  =  K ;
         K  =  P ;
        /*save the left child and its parent to visit the left branch after done with right one*/
         if( ( Lc_ATib ( P ) != NULL )) {
           Push_PATib (& Parent_s , P ) ;
           Push_PATib (& S , Lc_ATib ( P ) ) ;
          
         } ;
         P  =  Rc_ATib ( P ) ;
        
       } ;
      /*Thanks to the loop we know that rc(k)=p=null then if lc(k)=null, k is a leaf*/
       if( Lc_ATib ( K ) == NULL) {
         Ass_element_V100i ( Testing_array , Index   , Struct1_Tib ( Node_value_ATib ( K )  ) ) ;
        /*add the element to result array*/
         Index  =  Index + 1 ;
        /*if the parent is not null we update the parent child field pointing to K to null then free K*/
         if( ( Gp != NULL )) {
           if( ( K == Rc_ATib ( Gp ) )) {
             Ass_rc_ATib ( Gp , NULL ) ;
             }
           else
             {
             Ass_lc_ATib ( Gp , NULL ) ;
            
           } ;
          
         } ;
         Free_node_ATib ( K ) ;
        
       } ;
      /*visit the left bransh*/
       if( ( ! Empty_stack_PATib ( S ) )) {
         Pop_PATib (& S , &P ) ;
         Pop_PATib (& Parent_s , &K ) ;
         }
       else
         {
        /*last element to visit is the root if it is treated we exit the loop*/
         if( ( K == Lbl_ltr_root )) {
           Stop  =  True ;
           }
        /*we re-visit the tree after deleting visited leaves*/
         else
           {
           P  =  Lbl_ltr_root ;
           K  =  NULL ;
          
         } ;
        
       } ;
      
     } ;
    
    }
  void Write_traversal (int *Index)
    {
      /** Local variables **/
      int Index1;

      /** Body of function **/
     printf ( " %s%s%s",BOLD, "the traversal result:\n",RESET ) ;
     for( Index1  =  1 ;Index1 <=  100 ; ++Index1){
      usleep(40000);
       printf ( "%s %d%s%s->%s",BOLD, Struct1_Tib(Node_value_ATib(Element_V50_100ATib(Result_array,*Index,Index1))),RESET,GREEN,RESET ) ;
      
     } ;
    
    }
  void Check_correctness (int *Index)
    {
      /** Local variables **/
      bool Check_result;
      int V;
      int Index1;
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;

      /** Body of function **/
     Check_result  =  True ;
     Index_l  =  Element_V10ATib ( Trees_array , Tree_number   ) ;
     if( ( *Index == 1 )) {
       _Px1 =  ( ( Tree_number - 1 ) * 4 ) + 1 ;
       Write_traversal ( &_Px1) ;
       Check_correctness_byb_ltr ( & Index_l ) ;
       printf ( "%s%s %s %s",BOLD,YELLOW, "\nCheck traversal result: \n",RESET ) ;
       for( Index1  =  1 ;Index1 <=  100 ; ++Index1){
               printf ( "%s %d%s%s->%s",BOLD, Element_V100i(Testing_array,Index1),RESET,GREEN,RESET ) ;
                     usleep(40000);
         V  =  Struct1_Tib ( Node_value_ATib ( Element_V50_100ATib ( Result_array , ( ( Tree_number - 1 ) * 4 ) + 1 , Index1   ) )  ) ;
         if( ( ( Element_V100i ( Testing_array , Index1   ) ) != V )) {
           Check_result  =  False ;
          
         } ;
        
       } ;
       printf ( "%s%s %s%s",BOLD,YELLOW, "\nCheck result: ",RESET );
       if (Check_result)
        printf ( "%s%s Correct %s",BOLD,GREEN,RESET) ;
        else   printf ( "%s%s FALSE %s",BOLD,RED,RESET) ;

       }
     else
       {
       if( ( *Index == 2 )) {
         printf ( " %s", "The traversal result:\n " ) ;
         _Px2 =  ( ( Tree_number - 1 ) * 4 ) + 2 ;
         Write_traversal ( &_Px2) ;
         Check_correctness_byb_rtl ( & Index_l ) ;
         printf ( "%s%s%s %s",BOLD,YELLOW, "\nCheck traversal result:\n",RESET ) ;
         for( Index1  =  1 ;Index1 <=  100 ; ++Index1){
               printf ( "%s %d%s%s->%s",BOLD, Element_V100i(Testing_array,Index1),RESET,GREEN,RESET ) ;
                     usleep(40000);
           V  =  Struct1_Tib ( Node_value_ATib ( Element_V50_100ATib ( Result_array , ( ( Tree_number - 1 ) * 4 ) + 2 , Index1   ) )  ) ;
           if( ( ( Element_V100i ( Testing_array , Index1   ) ) != V )) {
             Check_result  =  False ;
            
           } ;
          
         } ;
         printf ( "%s%s %s%s",BOLD,YELLOW, "\nCheck result: ",RESET );
       if (Check_result)
        printf ( "%s%s Correct %s",BOLD,GREEN,RESET) ;
        else   printf ( "%s%s FALSE %s",BOLD,RED,RESET) ;
         }
       else
         {
         if( ( *Index == 3 )) {
           printf ( " %s", "The traversal result:\n" ) ;
           _Px3 =  ( ( Tree_number - 1 ) * 4 ) + 3 ;
           Write_traversal ( &_Px3) ;
           Checkcorectness_lbl_ltr ( & Index_l ) ;
           printf ( "%s%s%s %s",BOLD,YELLOW, "\nCheck traversal result:\n",RESET ) ;
           for( Index1  =  1 ;Index1 <=  100 ; ++Index1){
               printf ( "%s %d%s%s->%s",BOLD, Element_V100i(Testing_array,Index1),RESET,GREEN,RESET ) ;
                     usleep(40000);
             V  =  Struct1_Tib ( Node_value_ATib ( Element_V50_100ATib ( Result_array , ( ( Tree_number - 1 ) * 4 ) + 3 , Index1   ) )  ) ;
             if( ( ( Element_V100i ( Testing_array , Index1   ) ) != V )) {
               Check_result  =  False ;
              
             } ;
            
           } ;
           printf ( "%s%s %s%s",BOLD,YELLOW, "\nCheck result: ",RESET );
       if (Check_result)
        printf ( "%s%s Correct %s",BOLD,GREEN,RESET) ;
        else   printf ( "%s%s FALSE %s",BOLD,RED,RESET) ;
           }
         else
           {
           if( ( *Index == 4 )) {
             printf ( " %s", "The traversal result:\n" ) ;
             _Px4 =  ( ( Tree_number - 1 ) * 4 ) + 4 ;
             Write_traversal ( &_Px4) ;
             Checkcorectness_lbl_rtl ( & Index_l ) ;
             printf ( "%s%s%s %s",BOLD,YELLOW, "\nCheck traversal result:\n",RESET ) ;
             for( Index1  =  1 ;Index1 <=  100 ; ++Index1){
               printf ( "%s %d%s%s->%s",BOLD, Element_V100i(Testing_array,Index1),RESET,GREEN,RESET ) ;
                     usleep(40000);
               V  =  Struct1_Tib ( Node_value_ATib ( Element_V50_100ATib ( Result_array , ( ( Tree_number - 1 ) * 4 ) + 4 , Index1   ) )  ) ;
               if( ( ( Element_V100i ( Testing_array , Index1   ) ) != V )) {
                 Check_result  =  False ;
                
               } ;
              
             } ;
             printf ( "%s%s %s%s",BOLD,YELLOW, "\nCheck result: ",RESET );
       if (Check_result)
        printf ( "%s%s Correct %s",BOLD,GREEN,RESET) ;
        else   printf ( "%s%s FALSE %s",BOLD,RED,RESET) ;
            
           } ;
          
         } ;
        
       } ;
      
     } ;
    
    }
  void Mainmenu()
    {
      /** Local variables **/
      int Choice;
      bool Exit;
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;
      int _Px5;
      int _Px6;
      int _Px7;
      int _Px8;

      /** Body of function **/
     Exit  =  False ;
     while( ( ! Exit )) {
  printf("%s",CLEAR);
  printf("%s%s%s",BOLD,"===== ALSDD TP2 (Z) By  ======\n",  RESET);
  printf("%s%s%s",BOLD, "BELGUESMIA OUSSAMA & BELLOUL WASSIM ZINE El DINE 1CP7\n ", RESET);
  printf("%s%s%s",YELLOW, "==============================================================================\n", RESET);
  printf("%s%s%s",GREEN,"The program has created 10 BST of 100 random value\n", RESET);
  printf("%s%s%s",BOLD,"You can perform the following tasks%s\n",  RESET);

  printf("%s ", BLUE);  // Start of blue color for menu options
  printf("  1. choose a tree (1-10)\n");
  printf("  2. check the tree correctness\n");
  printf("  3. travers the tree branch by branch from bottom to top  & from left to right\n");
  printf("  4. travers the tree branch by branch from bottom to top & from right to left\n");
  printf("  5. traverse the tree leaf by leaf from left right\n");
  printf("  6. traverse the tree leaf by leaf from right to left\n");
  printf("  7. check the corectness of the 1st traversal\n");
  printf("  8. check the corectness of the 2nd traversal\n");
  printf("  9. check the corectness of the 3rd traversal\n");
  printf(" 10. check the corectness of the 4th traversal\n");
  printf(" %s", RESET);  // Reset color to default

  printf(" 0. EXIT..\n");
  printf("Enter your choice:  ");

       scanf ( " %d", &Choice ) ;
       if( ( Choice == 1 )) {
           printf ( " Enter the number of tree you choose (1-10): " ) ;
         scanf ( " %d", &Tree_number ) ;
         while( ( Tree_number < 1 ) || ( Tree_number > 10 )) {
           printf ( " Enter the number of tree you choose (1-10): " ) ;
           scanf ( " %d", &Tree_number ) ;
          
         } ;
         }
       else
         {
         if( ( Choice == 2 )) {
           Index_l  =  Element_V10ATib ( Trees_array , Tree_number   ) ;
           printf ( "%s%s%s %s",BOLD,MAGENTA, "You chose option 2: check the tree correctness\n",RESET ) ;
           Test  =  Checkbst ( & Index_l , & Counter1 ) ;
           printf ( " %s%s%s",BOLD,YELLOW, "You are treating tree number: " );
           printf ( " %s%d \n",GREEN, Tree_number ) ;
           printf ( " %s%s",YELLOW, "The tree has: " );
           printf ( "%s %d",GREEN, Counter1 );
           printf ( "%s %s\n",YELLOW, " element" ) ;
           printf ( " %s", "The check result is : " );
        if (Test)
        printf ( "%s%s Correct %s",BOLD,GREEN,RESET) ;
        else   printf ( "%s%s FALSE %s",BOLD,RED,RESET) ;
           printf ( "\n%s%s%s %s",BOLD,YELLOW, "Traversal inorder:\n",RESET ) ;
           Inorder ( & Index_l ) ;
           }
         else
           {
           if( ( Choice == 3 )) {
             printf ( "%s%s %s%s",MAGENTA,BOLD, "You chose travers the tree branch by branch from bottom to top&from left to right  :\n",RESET ) ;
             _Px1 =  ( ( Tree_number - 1 ) * 4 ) + 1 ;
             Write_traversal ( &_Px1) ;
             }
           else
             {
             if( ( Choice == 4 )) {
               printf ( "%s%s %s%s",MAGENTA,BOLD, "You chose option 4: travers the tree branch by branch from bottom to top & from right to left  :\n",RESET ) ;
               _Px2 =  ( ( Tree_number - 1 ) * 4 ) + 2 ;
               Write_traversal ( &_Px2) ;
               }
             else
               {
               if( ( Choice == 5 )) {
                 printf ( "%s%s %s%s",MAGENTA,BOLD, "You chose option 5: traverse the tree leaf by leaf from left right :\n",RESET ) ;
                 _Px3 =  ( ( Tree_number - 1 ) * 4 ) + 3 ;
                 Write_traversal ( &_Px3) ;
                 }
               else
                 {
                 if( ( Choice == 6 )) {
                   printf ( "%s%s %s%s",MAGENTA,BOLD, "You chose option 6: traverse the tree leaf by leaf from right to left  :\n",RESET ) ;
                   _Px4 =  ( ( Tree_number - 1 ) * 4 ) + 4 ;
                   Write_traversal ( &_Px4) ;
                   }
                 else
                   {
                   if( ( Choice == 7 )) {
                     printf ( "%s%s %s%s",MAGENTA,BOLD, "You chose option 7: check the corectness of the 1st traversal  :\n",RESET ) ;
                     _Px5 =  1 ;
                     Check_correctness ( &_Px5) ;
                     }
                   else
                     {
                     if( ( Choice == 8 )) {
                       printf ( "%s%s %s%s",MAGENTA,BOLD, "You chose option 8: check the corectness of the 2nd traversal  :\n",RESET ) ;
                       _Px6 =  2 ;
                       Check_correctness ( &_Px6) ;
                       }
                     else
                       {
                       if( ( Choice == 9 )) {
                         printf ( "%s%s %s%s",MAGENTA,BOLD, "You chose option 9: check the corectness of the 3rd traversal  :\n",RESET ) ;
                         _Px7 =  3 ;
                         Check_correctness ( &_Px7) ;
                         }
                       else
                         {
                         if( ( Choice == 10 )) {
                           printf ( "%s%s %s%s",MAGENTA,BOLD, "You chose option 10: check the corectness of the 4th traversal :\n",RESET ) ;
                           _Px8 =  4 ;
                           Check_correctness ( &_Px8) ;
                           }
                         else
                           {
                           Exit  =  True ;
                          
                         }
                       }
                     }
                   }
                 }
               }
             }
           }
         }
       } ;
      printf("%s%s\nPress ENTER to continue..%s",RED,BOLD,RESET);
     getchar() ;getchar() ;
     } ;
     printf ( " %s", "\nExiting program....." ) ;
    
    }

  int main(int argc, char *argv[])
    {
     srand(time(NULL));
     Result_array = malloc(50*100 * sizeof(Pointer_ATib));
     int _Izw2;for (_Izw2=0; _Izw2<50*100; ++_Izw2)
       Result_array[_Izw2] = malloc( sizeof(Pointer_ATib ));
     Trees_array = malloc(10 * sizeof(Pointer_ATib));
     int _Izw3;for (_Izw3=0; _Izw3<10; ++_Izw3)
       Trees_array[_Izw3] = malloc( sizeof(Pointer_ATib ));
     Testing_array = malloc(100 * sizeof(int));
     Tree_number  =  1 ;
     M  =  10 ;
     N  =  100 ;
     Firstelement  =  True ;
     Counter1  =  0 ;
     for( T  =  1 ;T <=  M ; ++T){
       A  =  NULL ;
       Randombst ( & A , & N ) ;
       _Px1 =  Counter1 + 1 ;
       Byb_ltr ( & A , &_Px1) ;
       _Px2 =  Counter1 + 2 ;
       Byb_rtl ( & A , &_Px2) ;
       _Px3 =  Counter1 + 3 ;
       Leafbyleaf_ltr ( & A , &_Px3) ;
       _Px4 =  Counter1 + 4 ;
       Leafbyleaf_rtl ( & A , &_Px4) ;
       Counter1  =  Counter1 + 4 ;
       Ass_element_V10ATib ( Trees_array , T   , A ) ;
      
     } ;
     Mainmenu() ;
    
   
      system("PAUSE");
      return 0;
    }
