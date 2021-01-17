#pragma once

#include "../Basic/Defines.h"
#include "../Basic/Basic.h"
#include "../Foundation/CString.h"
#include "../Collections/Set/SimpleSet.h"

namespace easy {
	/*
	 * A container for characters such as ASCII or Unicode.
	 * 
	 * When creating a string of all the characters, prefer to use the human readable characters only.
	 * Making a string of all characters may lead to crashes, as it includes all kinds of strange chars.
	 */
	template<typename C>
	struct CharacterSet: StringRepresentable, SetEnumerable<C> {
		CharacterSet() {

		}

		virtual ~CharacterSet() {}

		// # Properties

		virtual CString name() const = 0;
		virtual integer count() const = 0;

		// Avoid printing/showing all of these directly as a string, may cause crashes.
		virtual SetIterator<C> enumerateAll() const = 0;

		// Characters than can be seen and read properly by humans. Control characters never show up here.
		virtual SetIterator<C> enumerateHumanReadable() const = 0;

		virtual SetIterator<C> enumerateAlphabetical() const = 0;
		virtual SetIterator<C> enumerateAlphabeticalUppercase() const = 0;
		virtual SetIterator<C> enumerateAlphabeticalLowercase() const = 0;

		virtual SetIterator<C> enumerateNumerical() const = 0;

		virtual SetIterator<C> enumerateAlphanumerical() const = 0;

		// Any non-alphanumerical, non-control characters, non-space characters.
		virtual SetIterator<C> enumerateSymbols() const = 0;

		// Avoid printing/showing these directly as a string, may cause crashes.
		virtual SetIterator<C> enumerateControls() const = 0;

		// Whitespace, indents, new lines, etc...
		virtual SetIterator<C> enumerateSpaceCharacters() const = 0;

		virtual C spaceCharacter() const = 0;

		// # StringRepresentable

		virtual CString toString() const {
			return SimpleSet<C>(beginEnumeration()).toString();
		}

		// # Enumeration

		virtual SetIterator<C> beginEnumeration() const = 0;
	};

	/*
	 * When creating a string of all the characters, prefer to use the human readable characters only.
	 * Making a string of all characters may lead to crashes, as it includes all kinds of strange chars.
	 */
	struct CharacterSetASCII: CharacterSet<character>, Copyable<CharacterSetASCII> {
	private:
		CString _name;

		CharacterSetASCII();
		CharacterSetASCII(CString name, SetIterator<character> iterator);

	public:
		static const CharacterSetASCII& standard();

		CharacterSetASCII(const CharacterSetASCII& other);

		virtual ~CharacterSetASCII();

		// # Properties

		virtual CString name() const;
		virtual integer count() const;

		// Avoid printing/showing all of these directly as a string, may cause crashes.
		virtual SetIterator<character> enumerateAll() const;

		// Characters than can be seen and read properly by humans. Control characters never show up here.
		virtual SetIterator<character> enumerateHumanReadable() const;

		virtual SetIterator<character> enumerateAlphabetical() const;
		virtual SetIterator<character> enumerateAlphabeticalUppercase() const;
		virtual SetIterator<character> enumerateAlphabeticalLowercase() const;

		virtual SetIterator<character> enumerateNumerical() const;

		virtual SetIterator<character> enumerateAlphanumerical() const;

		// Any non-alphanumerical, non-control characters, non-space characters.
		virtual SetIterator<character> enumerateSymbols() const;

		// Avoid printing/showing these directly as a string, may cause crashes.
		virtual SetIterator<character> enumerateControls() const;

		// Whitespace, indents, new lines, etc...
		virtual SetIterator<character> enumerateSpaceCharacters() const;

		virtual character spaceCharacter() const;

		// # Copyable

		virtual CharacterSetASCII copy() const;

		// # Enumeration

		virtual SetIterator<character> beginEnumeration() const;
	};
};