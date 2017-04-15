//
//  Linux.h
//  cpp11sdl
//
//  Created by George Oros on 4/15/17.
//  Copyright © 2017 George Oros. All rights reserved.
//

#ifndef Linux_h
#define Linux_h

/* Detect g++ */
#ifdef __GNUG__
/* Avoid clang here */
#ifndef __clang__

/* Linux specific stuff */
#define __linux_machine
#define __base_path "/home/goros/Pictures" 

#endif
#endif


#endif /* Linux_h */
