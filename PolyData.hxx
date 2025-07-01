#include <vector>
#include <tuple>

// VTK Scalar dataset attribute
template<typename T>
struct vScalarTable 
{
	std::vector<T> data;
	std::string name;
};

// VTK Vector dataset attribute
template<typename T>
struct vVectorTable
{
	std::vector<std::tuple<T,T,T>> data;
	std::string name;
};

// VTK dataset coloring lookup table
struct vLookupTable
{
	std:vector<std::tuple<float,float,float,float>> data;
	std::string name;
};

// A class for storing the PolyData that is to be written
template<typename T>
class PolyData
{
public:
	// Set a list of point coordinates for defining vertices, lines, polygons, and triangle strips
	void SetPoints();
	
	// Set up vertex cells (groups of points that have group data)
	void SetVerts();
	// Set up line cells (connected strings of points with line data)
	void SetLines();
	// Set up polygon cells (surfaces enclosed by a string of points)
	void SetPolys();
	// Set up cells made from triangle strips
	void SetStrips();
	
	// Add Look Up tables for coloring data
	void AddLookupTable();
	
	// Add scalar data to the data attached to each point
	void AddPointScalars();
	// Add color data to each point
	void AddPointColorScalars();
	// Add 3D normal vectors (magnitude = 1) to each point
	void AddPointNormals();
	// Add 3D vectors to each point
	void AddPointVectors();
	// Add texture coordinate data to each point
	void AddPointTexture();
	// Add tensor data to each point
	void AddPointTensors();
	
	// Add scalar data to the data attached to each cell
	void AddCellScalars();
	// Add color data to each cell (NOT IMPLEMENTED)
	void AddCellColorScalars();
	// Add 3D normal vectors (magnitude = 1) to each cell
	void AddCellNormals();
	// Add 3D vectors to each cell
	void AddCellVectors();
	// Add texture coordinate data to each cell
	void AddCellTexture();
	// Add tensor data to each cell
	void AddCellTensors();
private:
	std::vector<std::tuple<T,T,T>> points;
	std::vector<std::vector<int>> cells;
	std::tuple<int,int> vertIDs;
	std::tuple<int,int> lineIDs;
	std::tuple<int,int> polyIDs;
	std::tuple<int,int> stripIDs;
};