obj_c = open("./TxtGame/object.c", "w")
obj_h = open("./TxtGame/object.h", "w")


def close_files():
    obj_c.close()
    obj_h.close()

number_of_objects = 0
temp_obj_c = "\nOBJECT objs[] = {\n"

with open("./TxtGame/object.txt", "r") as f:
    for line in f:
        if line[0] == '*':
            break
        if line[0] == '`':
            new_line = line.lstrip('`')
            obj_c.write(new_line)
            continue
        elif line[0] == '~':
            new_line = line.lstrip('~')
            obj_h.write(new_line)
            continue
        #^^headers to the C files, determined by ~ and ` as to which the line belongs to
        elif line[0] == '-':
            obj_name = line.lstrip('-').rstrip().upper()
            obj_tags = obj_loc = obj_dest = obj_pros = "NULL"
            obj_det = '"you see nothing special"'
            obj_cont = '"you see"'
            obj_text = '"you cant get any closer"'
            obj_weight = obj_cap = obj_hp = "0"
            obj_desc = "{NULL"
            obj_val = "0 },\n"
            obj_h.write(f"#define {obj_name:15} (objs + {number_of_objects})\n")
            line = next(f).split(' ', 1)
            attribute_name = line[0]
            while 1:
                match attribute_name:
                    case "\tdescription":
                        obj_desc = "{" + line[1].rstrip()
                    case "\ttags":
                        obj_tags = "{" + line[1].rstrip() + ", NULL };\n"
                    case "\tlocation":
                        obj_loc = line[1].rstrip().upper()
                    case "\tdestination":
                        obj_dest = line[1].rstrip().upper()
                    case "\tprospect":
                        obj_pros = line[1].rstrip().upper()
                    case "\tdetails":
                        obj_det = line[1].rstrip()
                    case "\tcontents":
                        obj_cont = line[1].rstrip()
                    case "\ttextgo":
                        obj_text = line[1].rstrip()
                    case "\tweight":
                        obj_weight = line[1].rstrip()
                    case "\tcapacity":
                        obj_cap = line[1].rstrip()
                    case "\thealth":
                        obj_hp = line[1].rstrip()
                    case "\tvalue":
                        obj_val = line[1].rstrip() + "},\n"
                line = next(f).split(' ', 1)
                attribute_name = line[0]
                if attribute_name == "stop":
                    break
            
            if obj_dest != "NULL" and obj_pros == "NULL":
                obj_pros = obj_dest
            
            
            obj_c.write(f"static const char *tags{number_of_objects}[] = {obj_tags}")
            #{description, tags, location, destination, prospect, details, contents, textgo, weight, capacity, health, value}
            temp_obj_c += f"\t{obj_desc}, tags{number_of_objects}, {obj_loc}, {obj_dest}, {obj_pros}, {obj_det}, {obj_cont}, {obj_text}, {obj_weight}, {obj_cap}, {obj_hp}, {obj_val}"

            number_of_objects += 1
    temp_obj_c = temp_obj_c.rstrip(",\n")
    obj_c.write(temp_obj_c)
    obj_c.write('\n};')
    obj_h.write(f"#define END_OF_OBJS (objs + {number_of_objects})")

close_files()