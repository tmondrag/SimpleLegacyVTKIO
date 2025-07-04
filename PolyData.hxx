#include <vector>
#include <tuple>
#include <string>
#include <fstream>

// VTK Scalar dataset attribute
template<typename T>
struct vScalarTable 
{
	std::vector<T> data;
	std::string name;
	int numComponents;
};

// VTK Vector dataset attribute
template<typename T>
struct vVectorTable
{
	std::vector<std::tuple<T,T,T>> data;
	std::string name;
};

// VTK dataset coloring lookup table
// ParaView will ignore the specific colors defined in custom lookup tables but 
// if your scalar data refers to a custom lookup table, the scalars in the 
// scalar data have to be between 0.0 and 1.0. The values will be multiplied by 
// numColors - 1 in the graphical rendering of the data but not in the 
// spreadsheet view of the data
struct vLookupTable
{
	std:vector<std::tuple<float,float,float,float>> data;
	std::string name;
};

// VTK texture dataset attribute
template<typename T>
struct vTextureTable
{
	std::vector<std::tuple<T,T,T>> data;
	std::string name;
	int dim = 3;
};

// VTK tensor dataset attribute
template<typename T>
struct vTensorTable
{
	std::vector<std::tuple<T,T,T, T,T,T, T,T,T>> data;
	std::string name;
};

// A class for storing the PolyData that is to be written
template<typename T>
class PolyData
{
public:
	PolyData(std::string filepath);
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
	// Add 3D normal vectors (magnitude = 1) to each cell
	void AddCellNormals();
	// Add 3D vectors to each cell
	void AddCellVectors();
	// Add texture coordinate data to each cell
	void AddCellTexture();
	// Add tensor data to each cell
	void AddCellTensors();

	void WritePreamble();
	void WriteDataSet();
	void WriteDataAttributes();

private:
	std::fstream outFile;
	std::vector<std::tuple<T,T,T>> points;
	std::vector<std::vector<int>> cells;
	std::tuple<int,int> vertIDs;
	std::tuple<int,int> lineIDs;
	std::tuple<int,int> polyIDs;
	std::tuple<int,int> stripIDs;
	std::vector<vLookupTable> lookUpTables;
	std::vector<vScalarTable> pointScalarAttributes;
	std::vector<vVectorTable> pointVectorAttributes;
	std::vector<vVectorTable> pointNormalAttributes;
	std::vector<vTextureTable> pointTextureAttributes;
	std::vector<vTensorTable> pointTensorAttributes;
	std::vector<vScalarTable> cellScalarAttributes;
	std::vector<vVectorTable> cellVectorAttributes;
	std::vector<vVectorTable> cellNormalAttributes;
	std::vector<vTextureTable> cellTextureAttributes;
	std::vector<vTensorTable> cellTensorAttributes;

	template<typename K>
	void _writeScalarData();
};

template<typename T>
inline PolyData<T>::PolyData(std::string filepath)
{
	this->outFile.open(filepath, std::fstream::out);
}

template<typename T>
inline void PolyData<T>::SetPoints()
{

}

template<typename T>
inline void PolyData<T>::SetVerts()
{
}

template<typename T>
inline void PolyData<T>::SetLines()
{
}

template<typename T>
inline void PolyData<T>::SetPolys()
{
}

template<typename T>
inline void PolyData<T>::WritePreamble()
{ 
	this->outFile << "# vtk DataFile Version 3.0" << std::endl;
	this->outFile << "Title for this data" << std::endl;
	this->outFile << "ASCII" << std::endl;
}

template<typename T>
inline void PolyData<T>::WriteDataSet()
{ 
	this->outFile << "DATASET oopsie, unimplemented datatype"
}

template<>
inline void PolyData<int>::WriteDataSet()
{
	this->outFile << "DATASET POLYDATA" << std::endl;
	this->outFile << "POINTS " << this->points.size << " int" << std::endl;
}

template<>
inline void PolyData<unsigned int>::WriteDataSet()
{
	this->outFile << "DATASET POLYDATA" << std::endl;
	this->outFile << "POINTS " << this->points.size << "  unsigned_int" << std::endl;
}

template<>
inline void PolyData<float>::WriteDataSet()
{
	this->outFile << "DATASET POLYDATA" << std::endl;
	this->outFile << "POINTS " << this->points.size() << " float" << std::endl;
}

template<>
inline void PolyData<double>::WriteDataSet()
{
	this->outFile << "DATASET POLYDATA" << std::endl;
	this->outFile << "POINTS " << this->points.size() << " double" << std::endl;
}

template<typename T, typename K>
inline void PolyData<T>::_writeScalarData<K>(std::vector<vScalarTable<K>> ScalarAttributes)
{

}

template<typename T>
inline void PolyData<T>::WriteDataAttributes()
{
	unsigned int numPoints = this->points.size();
	unsigned int numCells = this->cells.size();
	unsigned int attributeSize = this->pointScalarAttributes.size();

	attributeSize += this->pointNormalAttributes.size();
	attributeSize += this->pointVectorAttributes.size();
	attributeSize += this->pointTextureAttributes.size();
	attributeSize += this->pointTensorAttributes.size();
	if (attributeSize < 0)
	{
		this->outFile << "POINT_DATA " << numPoints << std::endl;
		if (this->pointScalarAttributes.size() != 0)
		{

		}
		if (this->pointNormalAttributes.size() != 0)
		{

		}
		if (this->pointVectorAttributes.size() != 0)
		{

		}
		if (this->pointTextureAttributes.size() != 0)
		{

		}
		if (this->pointTensorAttributes.size() != 0)
		{

		}
	}

	attributeSize = this->cellScalarAttributes.size();
	attributeSize += this->cellNormalAttributes.size();
	attributeSize += this->cellVectorAttributes.size();
	attributeSize += this->cellTextureAttributes.size();
	attributeSize += this->cellTensorAttributes.size();
	if (attributeSize < 0)
	{
		this->outFile << "CELL_DATA " << numCells << std::endl;
		if (this->cellScalarAttributes.size() != 0)
		{

		}
		if (this->cellNormalAttributes.size() != 0)
		{

		}
		if (this->cellVectorAttributes.size() != 0)
		{

		}
		if (this->cellTextureAttributes.size() != 0)
		{

		}
		if (this->cellTensorAttributes.size() != 0)
		{

		}
	}
		
	

}
