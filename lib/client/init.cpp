
/* Copyright (c) 2005, Stefan Eilemann <eile@equalizergraphics.com> 
   All rights reserved. */

#include "init.h"

#include "client.h"
#include "global.h"
#include "node.h"
#include "nodeFactory.h"
#include "version.h"

#include <eq/net/init.h>

using namespace eq;
using namespace eqBase;
using namespace std;

bool eq::init( int argc, char** argv )
{
    EQINFO << "Equalizer v" << Version::getString() << " initializing" << endl;

    // We do not use getopt_long because of:
    // - reordering of arguments
    // - different behaviour of GNU and BSD implementations
    // - incomplete man pages

    for( int i=1; i<argc; ++i )
    {
        if( strcmp( "--eq-server", argv[i] ) == 0 )
        {
            ++i;
            if( i<argc )
                Global::setServer( argv[i] );
        }
    }
    
    RefPtr<eqNet::Node> node = new Client;
    eqNet::Node::setLocalNode( node );

    char* argvListen[argc+1];
    
    for( int i=0; i<argc; i++ )
        argvListen[i] = argv[i];

    argvListen[argc] = "--eq-listen";

    if( !eqNet::init( argc+1, argvListen ))
    {
        EQERROR << "Failed to initialise Equalizer network layer" << endl;
        eqNet::Node::setLocalNode( NULL );
        return false;
    }

    return true;
}

bool eq::exit()
{
    return eqNet::exit();
}
