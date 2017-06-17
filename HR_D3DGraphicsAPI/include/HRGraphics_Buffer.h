#pragma once
#include "HRGraphics_Prerequisites.h"

/*!*************************************************************************************************************************************************************************
* @file		HRGraphics_Buffer.h																																			   *
*																																										   *
* This file contains the Color class declaration, for mathematical operations to get colors and control the data on them.												   *
* The methods implemented in the class are:																																   *
* - Setting of the channels individually.																																   *
* - Obtaining color structures from another 4D vector to get information from.																							   *
* - Obtaining color data from another color.																															   *
*																																										   *
* @date         26-09-2016																																				   *
* @author		Manuel Aldair Santos Ram�n (ManuSanRam)																													   *
* @copyright	Infernal Coders S.A.																																	   *
***************************************************************************************************************************************************************************/

/*!*************************************************************************************************************************************************************************
 * @section External inclusions																																			   *
 * Here goes any file required for the correct compilation and functionality of the class declared																		   *
***************************************************************************************************************************************************************************/
#include "HRGraphics_Vertex.h"

namespace HR_SDK
{
	/*!********************************************************************************************************************************************************************
	***********************************************************************************************************************************************************************/
	struct GraphicsDevice;
	
	/*!********************************************************************************************************************************************************************
	***********************************************************************************************************************************************************************/
	struct GraphicsDeviceContext;
	
	/*!********************************************************************************************************************************************************************
	***********************************************************************************************************************************************************************/
	struct GraphicsBuffer;

	/*!*********************************************************************************************************************************************************************
	 * @brief Base class to create buffers for Graphics pipeline.																										   *
	***********************************************************************************************************************************************************************/
	class HR_D3DGRAPHICSAPI_EXPORT C_BufferBase
	{
	public:
		/*!*****************************************************************************************************************************************************************
		 * @Constructor																																					   *
		*******************************************************************************************************************************************************************/
		C_BufferBase()
		{
			//! Point buffer pointer to null memory 
			//m_Buffer = nullptr;
		}

		/*!*****************************************************************************************************************************************************************
		 * @brief Destructor																																			   *
		*******************************************************************************************************************************************************************/
		virtual ~C_BufferBase();
		

	public:
		/*!*****************************************************************************************************************************************************************
		 * @brief Buffer that will contain information to feed the GPU																									   *
		*******************************************************************************************************************************************************************/
		GraphicsBuffer* m_Buffer;
	};

	/*!*********************************************************************************************************************************************************************
	 * @brief Vertex buffer to load geometry into the GPU for rendering.																								   *
	 * This class loads vertices to be processed into the GPU through a DirectX device.																					   *
	 * Vertex array can grow dynamiclly. It can also get an existing vertex array.																						   *
	 * Vertex buffer object also loads data into GPU itself. Only requiring a device.																					   *
	***********************************************************************************************************************************************************************/
	template<typename VertexType>
	class HR_D3DGRAPHICSAPI_EXPORT C_VertexBuffer : public C_BufferBase
	{
	public:
		/*!*****************************************************************************************************************************************************************
		 * @brief Constructor																																			   *
		 * @return A Vertex buffer object 																																   *
		*******************************************************************************************************************************************************************/
		C_VertexBuffer()
		{
			//! Point buffer pointer to null memory, to prevent it from carrying trash upon construction of object
			m_Buffer = NULL;
			//! Clear list to prevent trash to be built in creation of a buffer.
			m_Vertices.clear();
		}

		/*!*****************************************************************************************************************************************************************
		 * @brief Destructor																																			   *
		*******************************************************************************************************************************************************************/
		~C_VertexBuffer()
		{
			//! Data array is cleared and holds no more information
			m_Vertices.clear();
			Close();
		}

		/*!*****************************************************************************************************************************************************************
		 * @brief Adds a new vertex to the vertex array																													   *
		 * @param prm_Vertex Vertex that will be added to the buffer's vertex list.																						   *
		*******************************************************************************************************************************************************************/
		void AddVertex(VertexType prm_Vertex);

		/*!*****************************************************************************************************************************************************************
		 * @brief Constructs the vertex array from another vector of vertices.																							   *
		 * @param prm_Vertices Vector of vertices used to be processed in the subresource																				   *
		*******************************************************************************************************************************************************************/
		void AddVertices(Vector<VertexType> prm_Vertices);

		/*!*****************************************************************************************************************************************************************
		 * @brief Gets the size of the vertex array of the buffer																										   *
		 * @return Returns the size of the vector of vertices																											   *
		*******************************************************************************************************************************************************************/
		uint32 GetCount() { return m_Vertices.size(); }

		/*!*****************************************************************************************************************************************************************
		* @brief Creates the buffer and its data into the GPU.																											   *
		* @param prm_Device Pointer to DirectX device																													   *
		* @return Returns true when buffer is correctly created with all its data into the GPU																			   *
		*******************************************************************************************************************************************************************/
		bool Create
		(
			GraphicsDevice* prm_Device,
			D3D_Binds::E prm_Bind,
			D3D_Access::E prm_Access,
			D3D_Usages::E prm_Usage
		);

		/*!*****************************************************************************************************************************************************************
		* @brief Set the buffer into the device context.																												   *
		* @param prm_DC Device context used to pass the buffer into te input assembler stage																			   *
		* @return returns true when buffer is set into the Input assembler stage, false when something went wrong														   *
		*******************************************************************************************************************************************************************/
		void SetBuffer
		(
			GraphicsDeviceContext* prm_DC
		);

		/*!
		*/
		void Close
		(

		);

		/*!*****************************************************************************************************************************************************************
		 * @brief Array that holds the data of the vertices that will be processed to the GPU																			   *
		*******************************************************************************************************************************************************************/
		Vector<VertexType> m_Vertices;
	};

	/*!*********************************************************************************************************************************************************************
	 * @brief Declares an index buffer object, used to create indices for 3D geometry																					   *
	***********************************************************************************************************************************************************************/
	template<typename IndexType>
	class HR_D3DGRAPHICSAPI_EXPORT C_IndexBuffer : public C_BufferBase
	{
	public:
		/*!*****************************************************************************************************************************************************************
		* @brief Constructor (Default)																																	   *
		*******************************************************************************************************************************************************************/
		C_IndexBuffer()
		{
			m_Buffer = nullptr;
			m_Indices.clear();
		}

		/*!*****************************************************************************************************************************************************************
		* @brief Destructor																																				   *
		*******************************************************************************************************************************************************************/
		~C_IndexBuffer()
		{
			//! Clear the data inside the data array
			m_Indices.clear();
			Close();
		}
		
		/*!*****************************************************************************************************************************************************************
		* @brief Adds an index into the buffer's data array.																											   *
		* @param prm_Index Index to be inserted to the list.																											   *
		*******************************************************************************************************************************************************************/
		void AddIndex(IndexType prm_Index);

		/*!*****************************************************************************************************************************************************************
		* @brief Pass an array of precreated indices to the buffer's data array																							   *
		* @param prm_Indices Vector that contains indices to be passed to the GPU																						   *
		*******************************************************************************************************************************************************************/
		void AddIndices(Vector<IndexType>& prm_Indices);

		/*!*****************************************************************************************************************************************************************
		* @brief Het how many indices are stored inside the buffer's data array																							   *
		*******************************************************************************************************************************************************************/
		uint32 GetCount() { return m_Indices.size(); }

		/*!*****************************************************************************************************************************************************************
		* @brief Creates the buffer and its data into the GPU.																											   *
		* @param prm_Device Pointer to DirectX device																													   *
		* @return Returns true when buffer is correctly created with all its data into the GPU																			   *
		*******************************************************************************************************************************************************************/
		bool Create
		(
			GraphicsDevice* prm_Device,
			D3D_Binds::E prm_Bind,
			D3D_Access::E prm_Access,
			D3D_Usages::E prm_Usage
		);

		/*!*****************************************************************************************************************************************************************
		* @brief Set the buffer into the device context.																												   *
		* @param prm_DC Device context used to pass the buffer into te input assembler stage																			   *
		* @return returns true when buffer is set into the Input assembler stage, false when something went wrong														   *
		*******************************************************************************************************************************************************************/
		void SetBuffer
		(
			GraphicsDeviceContext*	prm_DC,
			DXGI_Formats::E			prm_Format
		);

		/*!****************************************************************************************************************************************************************
		*******************************************************************************************************************************************************************/
		void Close
		(

		);

		/*!*****************************************************************************************************************************************************************
		* @brief List of indices to be passed to the GPU																												   *
		*******************************************************************************************************************************************************************/
		Vector<IndexType>	m_Indices;
	};

	/*!*********************************************************************************************************************************************************************
	* @brief Declares a constant buffer, object used to pass information to GPU for graphics rendering																	   *
	***********************************************************************************************************************************************************************/
	class HR_D3DGRAPHICSAPI_EXPORT C_ConstantBuffer : public C_BufferBase
	{
	public:
		/*!*****************************************************************************************************************************************************************
		* @brief Constructor																																			   *
		*******************************************************************************************************************************************************************/
		C_ConstantBuffer()
		{
			m_Buffer = nullptr;
		}

		/*!*****************************************************************************************************************************************************************
		* @brief Destructor																																				   *
		*******************************************************************************************************************************************************************/
		~C_ConstantBuffer()
		{
			Close();
		}

		/*!****************************************************************************************************************************************************************
		 * @brief Creates the buffer and its data into the GPU.																											   
		 * @param prm_Device Pointer to DirectX device
		 * @param
		 * @param
		 * @param
		 * @return Returns true when buffer is correctly created with all its data into the GPU																			   
		*******************************************************************************************************************************************************************/
		bool Create
		(
			GraphicsDevice* prm_Device,
			D3D_Binds::E	prm_Bind,
			D3D_Access::E	prm_Access,
			D3D_Usages::E	prm_Usage,
			SIZE_T			prm_Size
		);

		/*!
		*/
		bool Map
		(
			GraphicsDeviceContext* prm_DC,
			void*,
			SIZE_T
		);

		/*!
		*/
		void Set
		(
			GraphicsDeviceContext* prm_DC,
			uint32		prm_Slot,
			uint32		prm_NumBuffers
		);

		/*!*/
		void Close
		(

		);
	};

	/*!
	*/
	typedef C_VertexBuffer<S_Vertex> C_VBuffer;
	
	/*!
	*/
	typedef C_IndexBuffer<uint16> C_IBuffer16;
	
	/*!
	*/
	typedef C_IndexBuffer<uint32> C_IBuffer32;
}