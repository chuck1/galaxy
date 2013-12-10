#ifndef __GAL_SIG_CONNECTION_HPP__
#define __GAL_SIG_CONNECTION_HPP__

#include <functional>


namespace gal
{
	namespace sig
	{
		template <typename... Args> class signal;

		template <typename... Args> class connection
		{
			public:
				friend class gal::sig::signal<Args...>;
			protected:
				connection( std::function<int(Args...)> handle ):
					handle_( handle )
			{

			}
			public:
				~connection()
				{

				}
			protected:
				std::function<int(Args...)>	handle_;
		};
	}
}

#endif




