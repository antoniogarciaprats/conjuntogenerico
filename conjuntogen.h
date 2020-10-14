
#ifndef CONJUNTOGEN	
#define CONJUNTOGEN

struct cj_int {
	int x;
};

typedef struct conj_rep *conj_enteros;

conj_enteros conjunto_enteros_crea ( void );
void conj_enteros_insertar ( conj_enteros *c, cj_int e,
		int (*compar) ( const void *, const void * ));
void conj_enteros_borrar ( conj_enteros *c, cj_int e,
		int (*compar) ( const void *, const void * ));
int conj_enteros_miembro ( conj_enteros c, struct cj_int e,
		int (*compar) ( const void *, const void * ));
int conj_enteros_tama ( conj_enteros *c );
void conj_enteros_destruir ( conj_enteros *c );

conj_enteros conj_enteros_union ( conj_enteros c, conj_enteros d,
		int (*compar) ( const void *, const void * ));

conj_enteros conj_enteros_interseccion ( conj_enteros c, conj_enteros d,
		int (*compar) ( const void *, const void * ));

conj_enteros conj_enteros_diferencia ( conj_enteros c, conj_enteros d,
		int (*compar) ( const void *, const void * ));




#endif
