#include "game.h"
#include <Windows.h>
#include <conio.h>
#include "threads.h"

using namespace game;
using namespace threads;
using namespace gamemap;
using namespace visualization;

// TODO: move to ini-file
const int MINX = 0;
const int MINY = 0;
const int MAXX = 20;
const int MAXY = 10;
const int SLEEP_TIME = 300;

CGame::CGame()
   : map( TCoords{ MINX, MINY }, TCoords{ MINY, MAXY } )
   , visual( map )
{
}

void CGame::start()
{
   initData();
   loop = true;
   CThread<CGame> gameLoop( this, &CGame::gameLoop );
   CThread<CVisualizator> visualLoop( &this->visual, &CVisualizator::gameLoop );
   _eventHandler();
   visual.stop();
   loop = false;
}

void CGame::_eventHandler()
{
   int key = 0;
   do
   {
      key = _getch(); // TODO: process 0-key
      key = eventHandler( key );

      key = (key == 27) ? -key : key;
   } while ( key >= 0 );
}

void CGame::gameLoop()
{
   while (loop)
   {
      step();
      Sleep( SLEEP_TIME );
   }
}

IObject::Ptr CGame::addObject( IObject::Ptr object, coord x, coord y )
{
   map.addObject( object, TCoords{ x, y } );
   return object;
}

void CGame::moveObject( IObject::Ptr object, coord x, coord y )
{
   map.moveObject( object, TCoords{ x, y } );
}

void CGame::addObjectToMap( IObject::Ptr object, coord x, coord y )
{
   map.addObject( object, TCoords{ x, y } );
}

void CGame::removeObjectFromMap( IObject::Ptr object )
{
   map.removeObject( object );
}

IObject::Ptr CGame::getObject( TObjectType objType, coord x, coord y )
{
   return map.getObject( TCoords{ x, y }, objType );
}

void CGame::creatureCarryItem( ICreature::Ptr creature )
{
   //TCoords coords = creature->getCoords();
   //IObject::Ptr obj = map.getObject( coords, TObjectType::item );
   //if ( obj != nullptr )
   //{
   //   removeObjectFromMap( obj );
   //   creature->carryItem( reinterpret_cast <CItem*>(obj) );
   //}
}

void CGame::creatureDropItem( ICreature::Ptr creature )
{
   //CItem* item = creature->getItem();
   //if ( item != nullptr )
   //{
   //   creature->dropItem( item );
   //   addObjectToMap( item, creature->getx(), creature->gety() );
   //}
}
