#include "Icosahedron.h"

Icosahedron::Icosahedron()
{
	double X = .525731112119133606f;
	double Z = .850650808352039932f;
	double N = 0.f;
	points.push_back({ -X, N, Z });
	points.push_back({ X, N, Z });
	points.push_back({ -X,N,-Z } );
	points.push_back({ X,N,-Z });
	points.push_back({ N,Z,X } );
	points.push_back({ N,Z,-X } );
	points.push_back({ N,-Z,X } );
	points.push_back({ N,-Z,-X });
	points.push_back({ Z,X,N } );
	points.push_back({ -Z,X, N } );
	points.push_back({ Z,-X,N } );
	points.push_back({ -Z,-X, N });

	lines.push_back({ 0, 4 });
	lines.push_back({ 0, 1 });
	lines.push_back({ 4, 1 });
	lines.push_back({ 0, 9 });
	lines.push_back({ 9, 4 });
	lines.push_back({ 5, 9 });
	lines.push_back({ 5, 4 });
	lines.push_back({ 9, 4 });
	lines.push_back({ 5, 8 });
	lines.push_back({ 8, 4 });
	lines.push_back({ 1, 8 });
	lines.push_back({ 10, 8 });
	lines.push_back({ 10, 1 });
	lines.push_back({ 10, 3 });
	lines.push_back({ 3, 8 });
	lines.push_back({ 5, 3 });
	lines.push_back({ 5, 2 });
	lines.push_back({ 3, 2 });
	lines.push_back({ 3, 7 });
	lines.push_back({ 2, 7 });
	lines.push_back({ 10, 7 });
	lines.push_back({ 10, 6 });
	lines.push_back({ 7, 6 });
	lines.push_back({ 11, 6 });
	lines.push_back({ 11, 7 });
	lines.push_back({ 11, 0 });
	lines.push_back({ 6, 0 });
	lines.push_back({ 6, 1 });
	lines.push_back({ 6, 1 });
	lines.push_back({ 1, 10 });
	lines.push_back({ 9, 11 });
	lines.push_back({ 11, 0 });
	lines.push_back({ 9, 2 });
	lines.push_back({ 2, 11 });
	lines.push_back({ 9, 5 });
	lines.push_back({ 11, 7 });

	centerPoint = { 0,0,0 };
	velocity = {0,0,0};
	moveCounter = 0;
	calculateAABB();
}
