#pragma once

/*!************************************************************************************************************************************************************************
*
*	@file		HRCore_Application.h
*
*	This file contains the declaration of class C_Application.
*	This class is used as an interface to create, control and render applications in any platform.
*	The basic functions of this class are:
*	- Initialize: Starts the application, passing any parameters to correctly start up the application.
*	- Update: Updates the application's window and the logic of the application.
*	-
*
*	@date			26-09-2016
*	@author			Manuel Aldair Santos Ram�n (ManuSanRam)
*	@copyright		Infernal Coders S.A.
*
***************************************************************************************************************************************************************************/

#include "HRGraphics_Prerequisites.h"

#include <HRUtility_Color.h>

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
	struct GraphicsSwapChain;
	/*!********************************************************************************************************************************************************************
	***********************************************************************************************************************************************************************/
	struct GraphicsTexture;
	/*!********************************************************************************************************************************************************************
	***********************************************************************************************************************************************************************/
	struct GraphicsRenderTargetView;
	/*!********************************************************************************************************************************************************************
	***********************************************************************************************************************************************************************/
	struct GraphicsShaderResourceView;
	/*!********************************************************************************************************************************************************************
	***********************************************************************************************************************************************************************/
	struct GraphicsDepthStencilView;

	/*!********************************************************************************************************************************************************************
	***********************************************************************************************************************************************************************/
	class HR_D3DGRAPHICSAPI_EXPORT C_Texture
	{
	public:
		/*!****************************************************************************************************************************************************************
		*******************************************************************************************************************************************************************/
		C_Texture()
		{
			m_Texture = NULL;
			m_RTV = NULL;
			m_SRV = NULL;
		}
		/*!****************************************************************************************************************************************************************
		*******************************************************************************************************************************************************************/
		~C_Texture()
		{
			
		}

		/*!****************************************************************************************************************************************************************
		*******************************************************************************************************************************************************************/
		bool						CreateFromFile
		(
			const String&			prm_FileName,
			GraphicsDevice*			prm_Device,
			GraphicsDeviceContext*	prm_DC
		);
		/*!****************************************************************************************************************************************************************
		*******************************************************************************************************************************************************************/
		bool						CreateAsRTV(GraphicsDevice* prm_Device, GraphicsSwapChain* prm_SC);

		void						SetRTV(GraphicsDeviceContext* prm_DC, uint32 prm_NumViews, GraphicsDepthStencilView* prm_DSV);

		void						ClearRTV(GraphicsDeviceContext* prm_DC, C_LinearColor prm_Color);

		/*!****************************************************************************************************************************************************************
		*******************************************************************************************************************************************************************/
		void						Close();

	public:
		/*!****************************************************************************************************************************************************************
		*******************************************************************************************************************************************************************/
		GraphicsTexture*				m_Texture;
		/*!****************************************************************************************************************************************************************
		*******************************************************************************************************************************************************************/
		GraphicsShaderResourceView*		m_SRV;
		/*!****************************************************************************************************************************************************************
		*******************************************************************************************************************************************************************/
		GraphicsRenderTargetView*		m_RTV;
	};
}
