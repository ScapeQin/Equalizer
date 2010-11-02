
/* Copyright (c) 2010, Stefan Eilemann <eile@eyescale.ch> 
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 2.1 as published
 * by the Free Software Foundation.
 *  
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef EQ_ERROR_H
#define EQ_ERROR_H

#include <eq/fabric/error.h>

namespace eq
{
    using fabric::ERROR_NONE;

    /** Defines errors produced by Equalizer classes. */
    enum Error
    {
        ERROR_FRAMEBUFFER_UNSUPPORTED = fabric::ERROR_CUSTOM,
        ERROR_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT,
        ERROR_FRAMEBUFFER_INCOMPLETE_ATTACHMENT,
        ERROR_FRAMEBUFFER_INCOMPLETE_DIMENSIONS,
        ERROR_FRAMEBUFFER_INCOMPLETE_FORMATS,
        ERROR_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER,
        ERROR_FRAMEBUFFER_INCOMPLETE_READ_BUFFER,
        ERROR_FRAMEBUFFER_FULL_COLOR_TEXTURES,
        ERROR_FRAMEBUFFER_INITIALIZED,

        ERROR_CUDACONTEXT_DEVICE_NOTFOUND,
        ERROR_CUDACONTEXT_INIT_FAILED,
        ERROR_CUDACONTEXT_MISSING_SUPPORT,

        ERROR_WINDOWSYSTEM_UNKNOWN,
        ERROR_AGL_MISSING_SUPPORT,
        ERROR_GLX_MISSING_SUPPORT,

        ERROR_PIPE_NODE_NOTRUNNING,

        ERROR_AGLPIPE_DISPLAYS_NOTFOUND,
        ERROR_AGLPIPE_DEVICE_NOTFOUND,

        ERROR_GLXPIPE_DEVICE_NOTFOUND,
        ERROR_GLXPIPE_GLX_NOTFOUND,

        ERROR_WGLPIPE_AFFINITYDC_FAILED,
        ERROR_WGLPIPE_ENUMDISPLAYS_FAILED,
        ERROR_WGLPIPE_CREATEDC_FAILED,
        ERROR_WGLPIPE_ENUMGPUS_FAILED,
        ERROR_WGLPIPE_REGISTERCLASS_FAILED,
        ERROR_WGLPIPE_CREATEWINDOW_FAILED,
        ERROR_WGLPIPE_CHOOSEPF_FAILED,
        ERROR_WGLPIPE_SETPF_FAILED,
        ERROR_WGLPIPE_CREATECONTEXT_FAILED,
        ERROR_WGLPIPE_WGLEWINIT_FAILED,

        ERROR_SYSTEMWINDOW_PIXELFORMAT_NOTFOUND,
        ERROR_SYSTEMWINDOW_NO_PIXELFORMAT,

        ERROR_AGLWINDOW_NO_CONTEXT,
        ERROR_AGLWINDOW_CREATECONTEXT_FAILED,
        ERROR_AGLWINDOW_CREATEPBUFFER_FAILED,
        ERROR_AGLWINDOW_SETPBUFFER_FAILED,
        ERROR_AGLWINDOW_CREATEWINDOW_FAILED,
        ERROR_AGLWINDOW_SETWINDOW_FAILED,

        ERROR_GLXWINDOW_NO_DRAWABLE,
        ERROR_GLXWINDOW_NO_DISPLAY,
        ERROR_GLXWINDOW_CREATECONTEXT_FAILED,
        ERROR_GLXWINDOW_CREATEWINDOW_FAILED,
        ERROR_GLXWINDOW_GLXQUERYVERSION_FAILED,
        ERROR_GLXWINDOW_GLX_1_3_REQUIRED,
        ERROR_GLXWINDOW_NO_FBCONFIG,
        ERROR_GLXWINDOW_CREATEPBUFFER_FAILED,

        ERROR_CUSTOM = EQ_128KB
    };

    /** Print the error in a human-readable format. @version 1.0 */
    inline std::ostream& operator << ( std::ostream& os, const Error& error)
        { os << fabric::Error( error ); return os; }
}
#endif // EQ_ERROR_H
