/* dirclassifier
 * Copyright (C) 2018-2023 Killian Valverde
 *
 * This file is part of dirclassifier.
 *
 * dirclassifier is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * dirclassifier is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with dirclassifier. If not, see <http://www.gnu.org/licenses/>.
 */

//
// Created by Killian on 13/07/18.
//

#ifndef CATEGORIES_DIRCLASSIFIER_PROGRAM_HPP
#define CATEGORIES_DIRCLASSIFIER_PROGRAM_HPP

#include <filesystem>
#include <set>
#include <string>
#include <vector>

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>


namespace dirclassifier {


class program
{
public:
    program(
            std::filesystem::path src_pth,
            std::filesystem::path dest_pth,
            std::vector<std::string> catg_fles_nmes
    );
    
    int execute();

private:
    bool execute_directory(const std::filesystem::path& dir_pth);
    
    void visit_inode(const std::filesystem::path& dir_pth);
    
    bool is_inode_visited(const std::filesystem::path& dir_pth) const noexcept;
    
    bool parse_categories_file(
            const std::filesystem::path& dir_pth,
            const std::filesystem::path& catg_pth
    ) const;
    
    bool make_symlink(
            const std::filesystem::path& dir_pth,
            const std::filesystem::path& dest_pth,
            boost::property_tree::ptree& nod,
            const std::string& link_nme = ""
    ) const;

private:
    std::filesystem::path src_pth_;
    
    std::filesystem::path dest_pth_;
    
    std::vector<std::string> catg_fles_nmes_;
    
    std::set<std::uint64_t> vistd_inos_;
};


}


#endif
