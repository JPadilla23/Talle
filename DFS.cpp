/*
Ejemplo UwU
7 14
1 2
1 3
1 4
1 6
2 3
2 7
3 1
3 2
3 5
3 7
4 3
5 6
6 7
7 3
2
6
*/
#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define MAX 500
vector<int> ady[ MAX ];
bool visitado[ MAX ];
bool visitadoB[ MAX ];
int V;
int path[ MAX ];         

bool first;

void dfs_allPath( int u , int fin , int len ){
    visitado[ u ] = true;
    path[ len ] = u;                   

    if( u == fin ){                    
        first = true;
        for( int i = 0 ; i <= len ; ++i ){
            ( first ) ? printf("%d" , path[i]) : printf("->%d" , path[i] );
            first = false;
        }
        printf("\n");
        return;
    }

    for( int i = 0 ; i < ady[ u ].size(); ++i ){
        int v = ady[ u ][ i ];
        if( !visitado[ v ] ){
            dfs_allPath( v , fin , len + 1 );
            visitado[ v ] = false;
        }
    }
}

void bfs(int ini, int fin){
    queue<int> Q;
    Q.push( ini );
    while( !Q.empty() ){
       int actual = Q.front(); Q.pop();
       if( actual == fin )break;
       visitadoB[ actual ] = true;
       for( int i = 0 ; i < ady[ actual ].size() ; ++i ){
          if( !visitadoB[ ady[ actual ][ i ] ] ){
             printf("%d --> %d\n" , actual , ady[ actual ][ i ] ); 
             Q.push( ady[ actual ][ i ] );
          }
       }
    }
}


int main(){

    int  E , x , y, inicial , final;
    printf("Dame el numero de vertices y aristas: ");
    scanf("%d %d" , &V , &E );

    for(int i = 1 ; i <= E ; ++i ){
    	printf("Dame la arista %d: ", i);
        scanf("%d %d" , &x , &y );
        ady[ x ].push_back( y );
    }
    first = true;

    printf("Nodo raiz: ");
    scanf("%d" , &inicial );

    memset( visitado , 0 , sizeof( visitado ) );
    printf("Nodo Final: ");
    scanf("%d" , &final );
    printf("\nPosibles Rutas de inicial a final\n");
    dfs_allPath( inicial , final , 0 );
    bfs(inicial, final);
    return 0;
}
