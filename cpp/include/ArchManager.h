#pragma once

#include <include/RhinoInclude.h>
#include <vector>

using namespace std;

class ArchManager
{
private:


public:

	ArchManager();
	~ArchManager();

	void CreateMesh(ON_Mesh& mesh);

	void GetTriMesh(ON_Mesh& mesh);

	vector<double> GetVertices(ON_Mesh& mesh);

	//bool GetFaces(int* faceList);
};

