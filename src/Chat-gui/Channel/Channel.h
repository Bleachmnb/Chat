#pragma once


//#include <cpprest/filestream.h>

//using namespace utility;

#define MAXCHANNELTEXTHISTORY 5000
#define MAXCHANNELSTRINGLENGHT 300
#define MAXCHANNELNAMELENGHT 30

namespace ChatChannel
{
	class Channel
	{
		public:
			wchar_t name[MAXCHANNELNAMELENGHT];
			wchar_t *TextHistory[MAXCHANNELTEXTHISTORY];
			Channel();
			~Channel();


		private:
			bool AddMessageToHistory();
			wchar_t *ReturnHistoryMessage(int index);
			bool SendMessage();
	};
}