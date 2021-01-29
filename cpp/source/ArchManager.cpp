#include <include/ArchManager.h>

ArchManager::ArchManager()
{
}


ArchManager::~ArchManager()
{
}

void ArchManager::CreateMesh(ON_Mesh& mesh)
{
	const ON_3dPoint a(0, 0, 0);
	const ON_3dPoint b(20, 0, 0);
	ON_3dPoint c(20, 20, 20);
	ON_3dPoint d(0, 20, 0);

	ON_NurbsSurface* srf = RhinoCreateSurfaceFromCorners(a, b, c, d);

	ON_MeshParameters mp = ON_MeshParameters();
	srf->CreateMesh(mp, &mesh);
	srf->Destroy();
}

void ArchManager::GetTriMesh(ON_Mesh& mesh)
{
	mesh.ConvertQuadsToTriangles();
	mesh.Flip();

}

vector<double> ArchManager::GetVertices(ON_Mesh& mesh)
{
	vector<double> vertices;
	GetTriMesh(mesh);
	const int vCount = mesh.VertexCount();

	if (vCount != 0)
	{
		for (int i = 0; i < vCount; i++)
		{
			//int num = i * 3;
			/*vertexList[num + 0] = mesh->Vertex(i).x;
			vertexList[num + 1] = mesh->Vertex(i).y;
			vertexList[num + 2] = mesh->Vertex(i).z;*/
			vertices.push_back(mesh.Vertex(i).x);
			vertices.push_back(mesh.Vertex(i).y);
			vertices.push_back(mesh.Vertex(i).z);

		}
	}


	return vertices;
}

//bool ArchManager::GetFaces(int * faceList)
//{
//	GetTriMesh(mesh);
//	const int fCount = mesh->m_F.Count();
//
//	if (fCount == 0) return false;
//
//	for (int i = 0; i < fCount; i++)
//	{
//		int num = i * 3;
//		faceList[num + 0] = mesh->m_F[i].vi[0];
//		faceList[num + 1] = mesh->m_F[i].vi[1];
//		faceList[num + 2] = mesh->m_F[i].vi[2];
//	}
//	return false;
//}
