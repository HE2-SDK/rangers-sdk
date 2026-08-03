#pragma once

namespace csl::ut {
	template<typename T>
	class CircularBuffer {
	protected:
		T* m_pBegin{};
		T* m_pEnd{};
		T* m_pFirst{};
		T* m_pLast{};
		size_t m_count{};
		fnd::IAllocator* m_pAllocator{};
		
		T* get(size_t i) const
		{
			if (!this->m_pBegin)
				return nullptr;

			return &m_pBegin[(m_pFirst - m_pBegin + i) % (m_pEnd - m_pBegin)];
		}
	
	public:
		void reserve(size_t capacity) {
			m_pBegin = static_cast<T*>(m_pAllocator->Alloc(sizeof(T) * capacity, 16));
			m_pEnd = m_pBegin + capacity;
			m_pFirst = m_pBegin;
			m_pLast = m_pBegin;
			m_count = 0;
		}
		
		CircularBuffer(size_t in_capacity, fnd::IAllocator* allocator) : m_pAllocator{ allocator }
		{
			reserve(in_capacity);
		}
		
		~CircularBuffer()
		{
			for (size_t i = 0; i < this->capacity(); i++)
				this->m_pBegin[i].~T();

			if (m_pAllocator)
				m_pAllocator->Free(this->m_pBegin);
		}
		
		csl::fnd::IAllocator* get_allocator()
		{
			return m_pAllocator;
		}
		
		void push_back(const T& item)
		{
			if (m_count == capacity())
				m_pLast->~T();
			
			new (m_pLast) T{ item };
			m_pLast = m_pBegin + ((m_pLast - m_pBegin + 1) % capacity());

			if (m_count == capacity())
				m_pFirst = m_pLast;
			else
				++m_count;
		}

		void push_back(T&& item)
		{
			if (m_count == capacity())
				m_pLast->~T();
			
			new (m_pLast) T{ std::move(item) };
			m_pLast = m_pBegin + ((m_pLast - m_pBegin + 1) % capacity());

			if (m_count == capacity())
				m_pFirst = m_pLast;
			else
				++m_count;
		}
		
		bool empty() const
		{
			return this->m_count == 0;
		}
		
		void clear()
		{
			if (!empty()) {
				for (size_t i = 0; i < this->capacity(); i++)
					this->m_pBegin[i].~T();
					
				this->m_count = 0;
				this->m_pFirst = this->m_pBegin;
				this->m_pLast = this->m_pBegin;
			}
		}
		
		class iterator
		{
			CircularBuffer* m_buffer;
			size_t m_index;

		public:
			iterator(CircularBuffer* buffer, size_t index) : m_buffer(buffer), m_index(index)
			{
			}

			T& operator*()
			{
				return *m_buffer->get(m_index);
			}

			iterator& operator++()
			{
				++m_index;
				return *this;
			}

			bool operator!=(const iterator& other) const
			{
				return m_index != other.m_index;
			}
		};
		
		const T& operator[] (size_t i) const
		{
			return *this->get(i);
		}

		T& operator[] (size_t i)
		{
			return *this->get(i);
		}
		
		[[nodiscard]] iterator begin()
		{
			return iterator(this, 0);
		}

		[[nodiscard]] iterator end()
		{
			return iterator(this, m_count);
		}
		
		[[nodiscard]] size_t size() const
		{
			return m_count;
		}

		[[nodiscard]] size_t capacity() const
		{
			return m_pEnd - m_pBegin;
		}
	};
}
