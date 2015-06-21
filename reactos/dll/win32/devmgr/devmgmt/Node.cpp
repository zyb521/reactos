/*
* PROJECT:     ReactOS Device Manager
* LICENSE:     GPL - See COPYING in the top level directory
* FILE:        dll/win32/devmgr/devmgr/node.cpp
* PURPOSE:     Object for each device in the tree
* COPYRIGHT:   Copyright 2015 Ged Murphy <gedmurphy@reactos.org>
*
*/

#include "stdafx.h"
#include "devmgmt.h"
#include "Node.h"


/* PUBLIC METHODS *******************************************/

CNode::CNode(_In_ PSP_CLASSIMAGELIST_DATA ImageListData) :
    m_ImageListData(ImageListData),
    m_DeviceId(NULL),
    m_ClassImage(0)
{
    m_DisplayName[0] = UNICODE_NULL;
}

CNode::~CNode()
{
    Cleanup();
}


/* PRIVATE METHODS ******************************************/


void
CNode::Cleanup()
{
    if (m_DeviceId)
    {
        HeapFree(GetProcessHeap(), 0, m_DeviceId);
        m_DeviceId = NULL;
    }
}