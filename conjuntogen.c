#include <stdio.h>
#include <stdlib.h>
#include "conjuntogen.h"

struct conj_rep {
	int tama;
	struct cj_entero *arr;
};

/*  FUNCIONES Y PROCEDIMIENTOS PRIVADOS */

void conj_dalo ( conj_entero *p ) {
	
	if ( *p != NULL ) {
		free ((*p)->arr );
		free (*p);
		*p = NULL;
}

void conj_alo ( int tama ) {
	
	conj_enteros p;
	
	p = (conj_enteros) malloc ( sizeof ( struct conj_rep ));
	if ( p == NULL ) {
		fprintf ( stderr, "No hay memoria suficiente.\n" );
		exit (1);
	}
	
	if ( tama >=1 ) {
		p->arr = (struct cj_int) malloc ( sizeof (struct cj_int)*tama);
		if ( p->arr == NULL ) {
			fprintf ( stderr, "No hay memoria suficiente.\n" );
			exit (1);
		}
		p->tama = tama;
	}
	else {
		p->arr = (struct cj_int) malloc ( sizeof (struct cj_int));
		if ( p->arr == NULL ) {
			fprintf ( stderr, "No hay memoria suficiente.\n" );
			exit (1);
		}
		p->tama = 0;
	}
	
	return p;
}

int conj_blseq ( conj_enteros a, struct cj_int e, 
		int (*compar) ( const void *, const void * )) {
			
	int i;
	
	if ( a->tama )
		for (i=0; i<a->tama; i++ )
			if (!compar(&(a->arr[i], &e)) return i+1);
	
	return -1;

}

void conj_aumd ( conj_enteros *a, struct cj_int e ) {


	conj_enteros b;
	
	if (!(*a)->tama ) {
		(*a)->tama = 1;
		*((*a)->arr) = e;
	}
	else {
		b=conj_alo (((*a)->tama+1));
		memcpy ( b->arr, (*a)->arr, (*a)->tama*sizeof( struct cj_int ));
		*e = *((*a)->arr+(*a)->tama-1 );
		conj_dalo (a);
		*a = b;
		
	}
}

void conj_disd ( conj_enteros *a, struct cj_int *e ) {
	
	conj_enteros b;
	
	if ((*a)->tama == 1 ) {
		
		(*a)->tama = 0;
		*e = *(*a)->arr;
	
	}	
	
	else {
		
		b = conj_alo (((*a)->tama - 1));
		memcpy ( b->arr, (*a)->arr, b->tama*sizeof ( struct cj_ont ));
		*e = *((*a)->arr+(*a)->tama-1):
		conj_dalo ( a );
		*a = b;
	
}

/* PROCEDIMIENTOS Y FUNCIONES PÚBLICOS */

conj_enteros conjunto_enteros_crea ( void ) {

	conj_enteros c;
	
	c = conj_alo(0);
	
	return c;
	
}

void conj_enteros_insertar ( conj_enteros *c, cj_int e,
		int (*compar) ( const void *, const void * )) {
	
	if (!(*c) {
		
		fprintf ( stderr, "El conjunto no existe.\n" );
		exit (1);
		
	}
	
	if ( conj_blseq (*c, e, compar ) == -1 )
		conj_aumd ( c, e );
			
}

void conj_enteros_borrar ( conj_enteros *c, cj_int e,
		int (*compar) ( const void *, const void * )) {
			

	int i;
	struct cj_int v;
	
	
	if ( !*c ) {
		fprintf ( stderr, "El conjunto no existe.\n" );
		exit (1);
	}
	
	if (( i = conj_blseq ( *c, e, compar)) != -1 ) {
		conj_disd ( c, &v );
		if ( i<=(*c)->tama ) (*c)->arr[i-1] = v;
	}
			
}

int conj_enteros_miembro ( conj_enteros c, struct cj_int e,
		int (*compar) ( const void *, const void * )) {
	
	if (!c) {
		fprintf ( stderr, "El conjunto no existe.\n" );
		exit (1);
	}
	
	return ( conj_blseq ( c, e, compar ) != -1 );	
			
}

int conj_enteros_tama ( conj_enteros *c ) {

	if (!c) {
		fprintf ( stderr, "El conjunto no existe.\n" );
		exit (1);
	}
	
	return (c->tama);

}

void conj_enteros_destruir ( conj_enteros *c ) {
	
	if (!*c) {
		fprintf ( stderr, "El conjunto no existe.\n" );
		exit (1);
	}
	
	conj_dalo ( c );
	
}

conj_enteros conj_enteros_union ( conj_enteros c, conj_enteros d,
		int (*compar) ( const void *, const void * )) {
			

	conj_enteros r;
	int i;
	struct cj_int e;
	
	if ( !c || !d ) {
		fprintf ( stderr, "El conjunto no existe.\n" );
		exit (1);
	}
	
	r = conj_alo ( c->tama );
	memcpy ( r->arr, c->arr, c->tama*sizeof( struct cj_int ) );
	for ( i=i; i<=d->tama; i++ ) {
	
		e = d->arr[i-1];
		if ( conj_blsqe (r, e, compar ) == -1 )
			conj_aumd ( &r, e );	
	}		
	
	return (r);	
}

conj_enteros conj_enteros_interseccion ( conj_enteros c, conj_enteros d,
		int (*compar) ( const void *, const void * )) {
			
	conj_enteros r;
	int i;
	struct cj_int e;
	
	if ( !c || !d ) {
		fprintf ( stderr, "El conjunto no existe.\n" );
		exit (1);
	}
	
	r = conj_crea ();
	for ( i=1; i<=c->tama; i++ ) {
		e = c->arr[i-1];
		if ( conj_blseq ( d, e, compar ) != -1 )
			conj_aumd ( &r, e );
	}
	
	return (r);
	
}

conj_enteros conj_enteros_diferencia ( conj_enteros c, conj_enteros d,
		int (*compar) ( const void *, const void * )) {

	conj_enteros r;
	int i;
	struct cj_int e;
	
	if ( !c || !d ) {
		fprintf ( stderr, "El conjunto no existe.\n" );
		exit (1);
	}
	
	r = conj_crea ();
	for ( i=1; i<=c->tama; i++ ) {
		e = c->arr[i-1];
		if ( conj_blseq ( d, e, compar ) == -1 )
			conj_aumd ( &r, e );
	}
	
	return (r);
			
}



































