#include "game.h"
#include <Windows.h>
#include <conio.h>
#include "threads.h"

using namespace game;
using namespace threads;
using namespace gamemap;
using namespace visualization;

// TODO: move to ini-file
#define MINX 0
#define MINY 0
#define MAXX 20
#define MAXY 10
#define SLEEP_TIME 300

CGame::CGame()
   : map( MINX, MINY, MAXX, MAXY )
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

void CGame::addObject( CObject* object )
{
   objects.add( object );
}

CObject* CGame::addObject( CObject* object, const coord& x, const coord& y )
{
   addObject( object );
   map.addObject( object, TPoint( x, y ) );
   return object;
}

void CGame::moveObject( CObject* object, const coord& x, const coord& y )
{
   map.moveObject( object, TPoint( x, y ) );
}

void CGame::addObjectToMap( CObject* object, const coord& x, const coord& y )
{
   map.addObject( object, TPoint( x, y ) );
}

void CGame::removeObjectFromMap( CObject* object )
{
   map.removeObject( object );
}

CObject* CGame::getObject( const TObjectType& objType, const coord& x, const coord& y )
{
   return map.getObject( objType, TPoint( x, y ) );
}

void CGame::creatureCarryItem( CCreature* creature )
{
   CObject* obj = getObject( TObjectType::item, creature->getx(), creature->gety() );
   if ( obj != nullptr )
   {
      removeObjectFromMap( obj );
      creature->carryItem( reinterpret_cast <CItem*>(obj) );
   }
}

void CGame::creatureDropItem( CCreature* creature )
{
   CItem* item = creature->getItem();
   if ( item != nullptr )
   {
      creature->dropItem( item );
      addObjectToMap( item, creature->getx(), creature->gety() );
   }
}
