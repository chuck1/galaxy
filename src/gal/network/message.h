#ifndef __JESS_ASIO_MESSAGE_HPP__
#define __JESS_ASIO_MESSAGE_HPP__

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <memory> 
#include <deque>

namespace gal
{
	namespace network
	{
		/// message
		class message
		{
			public:
				/// shared__t
				typedef std::shared_ptr<message>		shared_t;
				/// function_t
				typedef std::function<void(shared_t)>		function_t;
				/// deque_t
				typedef std::deque<shared_t>			deque_t;
				/// header length
				enum
				{
					header_length = 4
				};
				/// max body length
				enum
				{
					max_body_length = 65536
				};
			public:
				/// ctor
				message();
				void			set(void const * const, unsigned int);
				void			reset_head();
				void			write(void const * const, size_t);
				void			read(void * const, size_t);
				/// data
				const char*		data() const;
				/// data
				char*			data();
				/// length
				std::size_t		length() const;
				/// body
				const char*		body() const;
				/// body
				char*			body();
				/// body length
				std::size_t		body_length() const;
				/// body length
				void			body_length(std::size_t);
				/// decode header
				bool			decode_header();
				/// encode header
				void			encode_header();
			private:
				/// data
				char			data_[header_length + max_body_length];
				char*			head_;
				/// body length
				std::size_t		body_length_;
		};
	}
}





#endif // __JESS_ASIO_MESSAGE_HPP__
