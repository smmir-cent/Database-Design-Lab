

/**
 * 
 * 
 * First Question
 * 
 * create or replace function find_phone(pn varchar(20)) returns TABLE(_message text) language plpgsql as $$ begin return query select case left(pn, 3) when '09' then 'Mobile Phone Number' when '021' then 'city=Tehran, last 8 digits='|| TRIM(right(pn, 8))::text || ', city code=021' when '031' then 'city=Esfahan, last 8 digits='|| TRIM(right(pn, 8))::text || ', city code=031' when '077' then 'city=Bushehr, last 8 digits='|| TRIM(right(pn, 8))::text || ', city code=077' when '051' then 'city=Mashahad, last 8 digits='|| TRIM(right(pn, 8))::text || ', city code=051' else 'Not valid phone number' end as _message from address where address.phone = pn; end; $$;
 * 
 * 
 * 
 * 
 * /





/**
 * 
 * 
 * Second Question
 * 
 * create function rental_date(start_d date, end_d date) returns TABLE(_customer_id smallint, _title character varying) language plpgsql as $$ begin return query select rental.customer_id,title from film, inventory, rental where rental_date between start_d and end_d and rental.inventory_id = inventory.inventory_id and inventory.film_id = film.film_id; end; $$;
 * 
 * 
 * /





/**
 * 
 * 
 * Third Question
 * create function rental_info(start_d date, end_d date) returns TABLE(_first_name character varying, _last_name character varying, _email character varying) language plpgsql as $$ begin return query select customer.first_name, customer.last_name, customer.email from customer, rental where customer.customer_id in ( select _customer_id from rental_date(start_d, end_d) ) and rental.customer_id = customer.customer_id and rental.return_date IS NULL; end; $$;
 * 
 * 
 * 
 * 
 * /






/**
 * 
 * 
 * Fourth Question
 * create function Logging() returns trigger language plpgsql as $$ begin if (select film.rental_duration from rental, inventory, film where rental.inventory_id = inventory.inventory_id and inventory.film_id = film.film_id) < extract(days from old.return_date - new.rental_date) then return query insert into log(customer_id, delay) values (new.customer_id, old.return_date - new.rental_date); end if; return null; end; $$; create trigger Logging before insert or update on rental for each row execute procedure Logging();
 * 
 * 
 * 
 * 
 * /






/**
 * 
 * 
 * Fifth Question
 * 
 * 
 * create procedure FifthQ(_v int) language plpgsql as $$ declare -- variable declaration begin update film set rental_duration = rental_duration + _v; end; $$;
 * 
 * 
 * 
 * /