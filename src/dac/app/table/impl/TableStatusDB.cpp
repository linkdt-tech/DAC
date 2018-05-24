//------------------------------------------------------------------------------
/*
 This file is part of dacd: https://github.com/dac/dacd
 Copyright (c) 2016-2018 Linkdt-Tech Technology Co., Ltd.
 
	dacd is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
 
	dacd is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
 */
//==============================================================================

#include <dac/app/table/TableStatusDB.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////
// class TxStoreStatus
////////////////////////////////////////////////////////////////////////////////////////////////////////
namespace ripple {

TableStatusDB::TableStatusDB(DatabaseCon* dbconn, Application*  app, beast::Journal& journal)
    : databasecon_(dbconn),app_(app),journal_(journal){
}

TableStatusDB::~TableStatusDB() {

}

}
