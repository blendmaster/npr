
#include <GL/glew.h>
#include <GL/glut.h>
#include <menucreator.h>
#include <cstdlib>
#include <iostream>

using namespace std;

namespace EZGraphics {

/* -------------------------------------- */

std::vector<MenuCreator::MENUENTRY> MenuCreator::s;
int MenuCreator::currentval;
std::map<int,MenuCreator::MENUHANDLER> MenuCreator::HandlerFunc;

/* -------------------------------------- */

static MenuCreator::MENUENTRY mkMENUENTRY ( string s, int a, int b, MenuCreator::MENUHANDLER f )
{
  return make_pair(make_pair(s,a),make_pair(b,f));
}

/* -------------------------------------- */

void MenuCreator::beginMenu()
{
  s.push_back(mkMENUENTRY(string(),BEGIN,0,NULL));
}

/* -------------------------------------- */

void MenuCreator::addMenuEntry ( const char *name, MENUHANDLER handler )
{
  s.push_back(mkMENUENTRY(string(name),ENTRY,currentval++,handler));
}

/* -------------------------------------- */

void MenuCreator::beginSubMenu ( const char *name )
{
  s.push_back(mkMENUENTRY(string(name),BEGINSUB,0,NULL));
}

/* -------------------------------------- */

void MenuCreator::menuHandlerBase ( int code )
{
  if (HandlerFunc.find(code)==HandlerFunc.end())
    {
      cerr << "Menu error: can't find handler; HOW IS THIS POSSIBLE?!?" << endl;
      exit(-1);
    }
  (*HandlerFunc[code])();
}

/* -------------------------------------- */

int MenuCreator::endSubMenu ( )
{
  int count = 0;
  vector<MENUENTRY>::reverse_iterator i = s.rbegin();
  for ( i = s.rbegin(); i!=s.rend(); ++i )
    {
      if ((*i).first.second==BEGINSUB)
	break;
      count++;
    }
  if (i==s.rend())
    {
      cerr << "Menu error: Improperly nested submenu" << endl;
      exit(-1);
    }
  string subname = (*i).first.first;
  int res = glutCreateMenu(menuHandlerBase);
  vector<MENUENTRY>::iterator start = (i+1).base();
  for ( vector<MENUENTRY>::iterator j=start+1; j!=s.end(); ++j )
    {
      if ((*j).first.second==ENTRY)
	{
	  glutAddMenuEntry((*j).first.first.c_str(),(*j).second.first);
	  HandlerFunc[(*j).second.first] = (*j).second.second;
	}
      else
	if ((*j).first.second==COLLAPSEDSUB)
	  glutAddSubMenu((*j).first.first.c_str(),(*j).second.first);
    }
  s.erase(start,s.end());
  s.push_back(mkMENUENTRY(subname,COLLAPSEDSUB,res,NULL));

  return res;
}

/* -------------------------------------- */

int MenuCreator::endMenu()
{
  if (s.size()==0 || (s[0]).first.second!=BEGIN)
    {
      cerr << "Menu error: has beginMenu() been called?" << endl;
      exit(-1);
    }
  int res = glutCreateMenu(menuHandlerBase);
  for ( vector<MENUENTRY>::iterator i = s.begin(); i!=s.end(); i++ )
    {
      switch((*i).first.second)
	{
	case BEGIN:
	  if (i!=s.begin())
	    {
	      cerr << "Menu error: it appears beginMenu() has been used more than once to create this menu!" << endl;
	      exit(-1);
	    }
	  break;
	case BEGINSUB:
	case ENDSUB:
	  cerr << "Menu error: Improperly nested submenu" << endl;
	  exit(-1);
	  break;
	case ENTRY:
	  glutAddMenuEntry((*i).first.first.c_str(),(*i).second.first);
	  HandlerFunc[(*i).second.first] = (*i).second.second;
	  
	  break;
	case COLLAPSEDSUB:
	  glutAddSubMenu((*i).first.first.c_str(),(*i).second.first);
	  break;
	default:
	  cerr << "Menu error: unknown code; HOW IS THIS POSSIBLE?!?" << endl;
	  exit(-1);
	}
    }
  s.clear();
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  return res;
}

/* -------------------------------------- */

};
