/* $Id: Date.hpp 103491 2007-05-04 17:18:18Z kazimird $
 * ===========================================================================
 *
 *                            PUBLIC DOMAIN NOTICE
 *               National Center for Biotechnology Information
 *
 *  This software/database is a "United States Government Work" under the
 *  terms of the United States Copyright Act.  It was written as part of
 *  the author's official duties as a United States Government employee and
 *  thus cannot be copyrighted.  This software/database is freely available
 *  to the public for use. The National Library of Medicine and the U.S.
 *  Government have not placed any restriction on its use or reproduction.
 *
 *  Although all reasonable efforts have been taken to ensure the accuracy
 *  and reliability of the software and data, the NLM and the U.S.
 *  Government do not and cannot warrant the performance or results that
 *  may be obtained by using this software or data. The NLM and the U.S.
 *  Government disclaim all warranties, express or implied, including
 *  warranties of performance, merchantability or fitness for any particular
 *  purpose.
 *
 *  Please cite the author in any work or product based on this material.
 *
 * ===========================================================================
 *
 * Author:  Aaron Ucko, NCBI
 *
 * File Description:
 *   Useful member functions for dates: comparison and formatting
 *
 * Remark:
 *   This code was originally generated by application DATATOOL
 *   using specifications from the ASN data definition file
 *   'general.asn'.
 */

#ifndef OBJECTS_GENERAL_DATE_HPP
#define OBJECTS_GENERAL_DATE_HPP


// generated includes
#include <objects/general/Date_.hpp>

#include <corelib/ncbitime.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

class NCBI_GENERAL_EXPORT CDate : public CDate_Base
{
    typedef CDate_Base Tparent;
public:
    // for conversion from CTime
    enum EPrecision {
        ePrecision_day,
        ePrecision_second
    };

    // constructors; the latter two make Date-stds
    CDate(void);
    CDate(const CTime& time, EPrecision prec = ePrecision_second);
    explicit CDate(time_t time, EPrecision prec = ePrecision_second);
    // destructor
    ~CDate(void);

    void  SetToTime(const CTime& time, EPrecision prec = ePrecision_second);
    CTime AsCTime  (CTime::ETimeZone tz = CTime::eLocal) const;

    enum ECompare {
        eCompare_before = -1,
        eCompare_same,
        eCompare_after,
        eCompare_unknown
    };
    ECompare Compare(const CDate& date) const;
    
    // Appends a date as a string to label. If internally, the date
    // is a string, the string is just returned. If internally the date
    // is a CDate_std and year_only is false, then the date is returned 
    // as mm-dd-yyyy if possible else, just year is returned
    void GetDate(string* label, bool year_only = false) const;

    // Format controls the treatment of Date-std.  (Strings
    // necessarily remain as is.)  Specifically,
    // %Y -> year
    // %M -> month as number
    // %N -> month as (English) word
    // %D -> day
    // %S -> season
    // %h -> hour
    // %m -> minute
    // %s -> second
    // Each of the above can contain a number immediately following the
    // percent sign, indicating the number of characters to yield.
    // 
    // In addition, there are special directives to deal with optional
    // elements: %{ ... %} (which may be nested) may be used to
    // delimit subsequences that should vanish altogether if optional
    // elements they contain are missing, and %| may be used to
    // designate fallbacks.  (For instance, the above interface
    // defaults to a format of "%{%2M-%2D-%}%Y, and one might format
    // dates for GenBank with "%{%{%2D%|01%}-%3N%|01-JAN%}-%Y" if one
    // wanted to fudge legal values if necessary.)
    //
    // Finally, %% -> %.
    void GetDate(string* label, const string& format) const;
    void GetDate(string* label, const char*   format) const;

private:
    // Prohibit copy constructor and assignment operator
    CDate(const CDate& value);
    CDate& operator=(const CDate& value);

};



/////////////////// CDate inline methods

// constructors
inline
CDate::CDate(void)
{
}

inline CDate::CDate(const CTime& time, CDate::EPrecision prec)
{
    SetToTime(time, prec);
}

inline CDate::CDate(time_t time, CDate::EPrecision prec)
{
    SetToTime(CTime(time), prec);
}


// old version of GetDate
inline
void CDate::GetDate(string* label, bool year_only) const
{
    GetDate(label, year_only ? "%Y" : "%{%2M-%2D-%}%Y");
}


// Make sure that stupid compilers don't try to cast char* to bool....
inline
void CDate::GetDate(string* label, const char* format) const
{
    GetDate(label, string(format));
}


/////////////////// end of CDate inline methods


END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

#endif // OBJECTS_GENERAL_DATE_HPP
/* Original file checksum: lines: 90, chars: 2320, CRC32: 5affaceb */