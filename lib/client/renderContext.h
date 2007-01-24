
/* Copyright (c) 2006-2007, Stefan Eilemann <eile@equalizergraphics.com> 
   All rights reserved. */

#ifndef EQ_RENDERCONTEXT_H
#define EQ_RENDERCONTEXT_H

#include <eq/base/base.h>
#include <eq/client/pixelViewport.h>
#include <eq/client/range.h>
#include <eq/vmmlib/VMMLib.h>

namespace eq
{
    /**
     * The context applied by the server during rendering operations.
     */
    struct RenderContext 
    {
    public:
        uint32_t       frameID;       //<! identifier from Config::beginFrame
        uint32_t       buffer;        //<! buffer as passed to glDrawBuffer()
        PixelViewport  pvp;           //<! pixel viewport of channel wrt window
        Range          range;         //<! database-range to be rendered
        vmml::Frustumf frustum;       //<! frustum for projection matrix
        vmml::Matrix4f headTransform; //<! frustum transform for modelview
    };

    EQ_EXPORT std::ostream& operator << ( std::ostream& os, 
                                          const RenderContext& ctx );
}

#endif // EQ_RENDERCONTEXT_H
